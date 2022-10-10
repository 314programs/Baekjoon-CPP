#include <bits/stdc++.h>
using namespace std;

long long DP[11][101][101][101];
long long pascal[11][11];
int tree_s, red, green, blue;

//Remember to always use long long...
long long solve(int level, int r, int g, int b){
    if(r < 0 || g < 0 || b < 0) return 0;
    if(level == tree_s+1) return 1;
    if(DP[level][r][g][b] != -1) return DP[level][r][g][b];

    DP[level][r][g][b] = 0;
    
    //Using 1 color
    DP[level][r][g][b] += solve(level+1, r-level, g, b);
    DP[level][r][g][b] += solve(level+1, r, g-level, b);
    DP[level][r][g][b] += solve(level+1, r, g, b-level);
    
    //Using 2 colors
    if(level%2 == 0){
        int i = level/2;
        //Multiply by the number of combinations...
        DP[level][r][g][b] += solve(level+1, r-i, g-i, b) * pascal[level][i];
        DP[level][r][g][b] += solve(level+1, r, g-i, b-i) * pascal[level][i];
        DP[level][r][g][b] += solve(level+1, r-i, g, b-i) * pascal[level][i];
    }
    
    //Using 3 colors
    if(level%3 == 0){
        int i = level/3;
        DP[level][r][g][b] += solve(level+1, r-i, g-i, b-i) * pascal[level][i] * pascal[level-i][i];
    }    

    return DP[level][r][g][b];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> tree_s >> red >> green >> blue;
    memset(DP, -1, sizeof(DP));

    memset(pascal, 0, sizeof(pascal));
    
    //Pascal's triangle for combinations
    pascal[0][0] = 1;
    for(int y = 1; y <= 10; y++){
        pascal[y][0] = 1;
        pascal[y][y] = 1;
        for(int x = 1; x < y; x++){
            pascal[y][x] = pascal[y-1][x] + pascal[y-1][x-1];
        }
    }

    cout << solve(1, red, green, blue);

}
