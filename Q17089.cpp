#include <bits/stdc++.h>
using namespace std;

int friends[4001][4001];
map<int, int> friend_count;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int ppl_num, friend_num;
    cin >> ppl_num >> friend_num;
    
    for(int i = 1; i <= ppl_num; i++){
        friend_count[i] = 0;
    }

    memset(friends, 0, sizeof(friends));
    for(int i = 0; i < friend_num; i++){
        int x, y;
        cin >> x >> y;

        friends[x][y] = 1;
        friends[y][x] = 1;
        friend_count[x]++;
        friend_count[y]++;
    }

    int ans = 1e+9;
    for(int i = 1; i <= ppl_num; i++){
        for(int j = i+1; j <= ppl_num; j++){
            if(friends[i][j] == 1){
                for(int k = j+1; k <= ppl_num; k++){
                    if(friends[j][k] == 1 && friends[k][i] == 1){
                        ans = min(friend_count[i] + friend_count[j] + friend_count[k] - 6, ans);
                    }
                }
            }
        }
    }
    if(ans != 1e+9) cout << ans;
    else cout << -1;

}
