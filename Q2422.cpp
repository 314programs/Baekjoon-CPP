#include <bits/stdc++.h>
using namespace std;

vector<int> num_list(3);
int visited[201];
int no[201][201];
int ans = 0;
void solve(int ice_cream_num, int count){
    if(count == 3){
        if(no[num_list[0]][num_list[1]] == 0 && no[num_list[1]][num_list[2]] == 0 && no[num_list[2]][num_list[0]] == 0){
            ans++;
        }
        return;
    }

    for(int i = 1; i <= ice_cream_num; i++){
        if(visited[i] == 0 && (count == 0 || num_list[count-1] < i)){
            visited[i] = 1;
            num_list[count] = i;
            solve(ice_cream_num, count+1);
            visited[i] = 0;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int ice_cream_num, worst_comb_num;
    cin >> ice_cream_num >> worst_comb_num;

    memset(visited, 0, sizeof(visited));
    memset(no, 0, sizeof(no));

    for(int i = 0; i < worst_comb_num; i++){
        int x, y;
        cin >> x >> y;
        no[x][y] = 1;
        no[y][x] = 1;
    }

    solve(ice_cream_num, 0);
    cout << ans;
}
