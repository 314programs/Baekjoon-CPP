#include <bits/stdc++.h>
using namespace std;

long long DP[101][101];
int song_cnt, between, needed;
long long mod = 1000000007;

long long solve(int p, int used){
    int un_used = song_cnt - used;
    if(p == needed){
        if(un_used == 0) return 1;
        return 0;
    }

    long long &ans = DP[p][used];
    if(ans != -1) return ans;
    ans = 0;

    //Adding unused music to the playlist
    if(un_used > 0){
        ans += solve(p+1, used+1) * un_used;
    }

    //Adding already used music to the playlist
    if(used > between){
        //Use the fact that only different types of music can be between same music
        ans += solve(p+1, used) * (used-between);
    }
    ans %= mod;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    memset(DP, -1, sizeof(DP));
    cin >> song_cnt >> between >> needed;
    cout << solve(0, 0);

}
