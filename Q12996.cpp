#include <bits/stdc++.h>
using namespace std;

long long DP[51][51][51][51];

long long solve(int song_cnt, int a, int b, int c){
    if(song_cnt == 0){
        if(a == 0 && b == 0 && c == 0) return 1;
        return 0;
    }
    
    //Memoization
    long long &ans = DP[song_cnt][a][b][c];
    if(ans != -1) return ans;
    ans = 0;

    for(int i = 0; i <= 1; i++){
        for(int j = 0; j <= 1; j++){
            for(int k = 0; k <= 1; k++){
                //Try every possibility except no one singing
                if(i == 0 && j == 0 && k == 0) continue;
                ans += solve(song_cnt-1, a-i, b-j, c-k);
            }
        }
    }

    ans %= 1000000007;
    return ans;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int song_cnt, a, b, c;
    cin >> song_cnt >> a >> b >> c;

    memset(DP, -1, sizeof(DP));
    cout << solve(song_cnt, a, b, c);

}
