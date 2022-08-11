#include <bits/stdc++.h>
using namespace std;

//Number of push ups, current score
bool DP[5001][5001];
int scores[10];
int p_cnt, score_cnt;

void solve(int p, int s){
    if(p == p_cnt){
        DP[p][s] = true;
        return;
    }

    if(DP[p][s]) return;
    DP[p][s] = true;

    for(int i = 0; i < score_cnt; i++){
        int next = scores[i];
        if(p+s+next <= p_cnt){
            solve(p+s+next, s+next);
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--){
        memset(DP, false, sizeof(DP));
        cin >> p_cnt >> score_cnt;
        for(int i = 0; i < score_cnt; i++){
            cin >> scores[i];
        }

        solve(0, 0);

        int ans = -1;
        for(int i = 0; i <= 5000; i++){
            if(DP[p_cnt][i] == true) ans = i;
        }
        cout << ans << "\n";

    }

}
