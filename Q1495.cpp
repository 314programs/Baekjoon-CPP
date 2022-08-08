#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int song_cnt, start_vol, max_vol;
    cin >> song_cnt >> start_vol >> max_vol;
      
    int songs[song_cnt];
    //Extra space for song_cnt to include starting volumne
    int DP[song_cnt+1][max_vol+1];
    for(int i = 0; i < song_cnt; i++){
        cin >> songs[i];
    }
    
    //Mark down the starting volume
    memset(DP, 0, sizeof(DP));
    DP[0][start_vol] = 1;

    for(int i = 0; i < song_cnt; i++){
        for(int j = 0; j <= max_vol; j++){
            //If can play next song using this volume
            if(DP[i][j] == 1){
                if(j + songs[i] <= max_vol) DP[i+1][j + songs[i]] = 1;
                if(j - songs[i] >= 0) DP[i+1][j - songs[i]] = 1;
            }
        }
    }
    
    //Find max at last song
    int ans = -1;
    for(int i = 0; i <= max_vol; i++){
        if(DP[song_cnt][i] == 1) ans = i;
    }
    cout << ans;

}
