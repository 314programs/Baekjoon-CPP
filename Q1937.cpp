#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int n;
int a[501][501];
//Stores maximum length of path
int DP[501][501];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int solve(int x, int y, int prev){
    int m = 1;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < n && a[ny][nx] > prev){
            if(DP[ny][nx] != 0){
                //Memoization moment, value already there
                m = max(m, DP[ny][nx]+1);
            }
            else{
                solve(nx, ny, a[ny][nx]);
                m = max(m, DP[ny][nx]+1);
            }
        }
    }

    DP[y][x] += m;
    return DP[y][x];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    memset(DP, 0, sizeof(DP));
    int ans = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            //Path has to be found
            if(DP[i][j] == 0) ans = max(ans, solve(j, i, a[i][j]));
            else{
                //Maximum already calculated
                ans = max(ans, DP[i][j]);
            }
        }
    }

    cout << ans;   

}
