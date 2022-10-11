#include <bits/stdc++.h>
using namespace std;

//Each point on DP is the right-down point on a square
int DP[1001][1001];
string s[1000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    int height, width;
    cin >> height >> width;
    for(int i = 0; i < height; i++){
        cin >> s[i];
    }

    int ans = 0;
    memset(DP, 0, sizeof(DP));

    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            if(s[y][x] == '1'){
                //Memoization
                DP[y][x] = min(min(DP[y-1][x], DP[y][x-1]), DP[y-1][x-1]) + 1;
                ans = max(ans, DP[y][x]);
            }
        }
    }

    cout << ans*ans;

}
