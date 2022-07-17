//Why did I struggle with this by getting the wrong concept?
#include <bits/stdc++.h>
using namespace std;

int graph[3][3];
int temp[3][3];
int ans = 1000;
int visited[10];

bool check(){
    int total = temp[0][0] + temp[1][1] + temp[2][2];
    if(total != temp[0][2] + temp[1][1] + temp[2][0]) return false;

    for(int y = 0; y < 3; y++){
        if(total != temp[y][0] + temp[y][1] + temp[y][2]) return false;
    }
    for(int x = 0; x < 3; x++){
        if(total != temp[0][x] + temp[1][x] + temp[2][x]) return false;
    }
    for(int i = 1; i <= 9; i++){
        if(visited[i] != 1) return false;
    }

    return true;
}

void backtrack(int idx, int work){
    if(idx == 9){
        if(check() == true){
            ans = min(ans, work);
        }
        return;
    }
    int x = idx%3, y = idx/3;
    for(int i = 1; i <= 9; i++){
        if(visited[i] == 0){
            visited[i] = 1;
            temp[y][x] = i;
            backtrack(idx+1, work + abs(graph[y][x] - i));
            visited[i] = 0;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    memset(visited, 0, sizeof(visited));
    for(int y = 0; y < 3; y++){
        for(int x = 0; x < 3; x++){
            cin >> graph[y][x];
        }
    }

    backtrack(0, 0);
    cout << ans;
}
