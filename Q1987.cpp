#include <bits/stdc++.h>
using namespace std;

int height, width;
char graph[20][20];

int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
int visited_alpha[26];

int ans = 1;

int calc(int y_, int x_, int depth){
    for(int i = 0; i < 4; i++){
        int ny_ = y_ + dy[i];
        int nx_ = x_ + dx[i];

        if(visited_alpha[graph[ny_][nx_] - 'A'] == 0 && ny_ >= 0 && ny_ < height && nx_ >= 0 && nx_ < width){
            visited_alpha[graph[ny_][nx_] - 'A'] = 1;
            ans = max(ans, calc(ny_, nx_, depth+1));
            visited_alpha[graph[ny_][nx_] - 'A'] = 0;
        }
    }
    return depth;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> height >> width;
    cin.ignore();

    for(int y = 0; y < height; y++){
        string temp;
        getline(cin, temp);
        for(int x = 0; x < width; x++){
            graph[y][x] = temp[x];
        }
    }

    memset(visited_alpha, 0, sizeof(visited_alpha));
    visited_alpha[graph[0][0] - 'A'] = 1;
    calc(0, 0, 1);
    cout << ans;

}


 
