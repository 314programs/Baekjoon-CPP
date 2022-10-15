#include <bits/stdc++.h>
using namespace std;

int a[51][51];
//i, j, previous arcade num, number of arcades visited
int DP[51][51][51][51];

const int mod = 1000007;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    //height, width
    int n, m, k;
    cin >> n >> m >> k;
    memset(a, -1, sizeof(a));

    for(int i = 0; i < k; i++){
        int c, d;
        cin >> c >> d;
        a[c][d] = i;
    }
    DP[1][0][0][0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            //Current space is not an arcade, and counts for the method of not visitng any arcades
            if(a[i][j] == -1){
                DP[i][j][0][0] += DP[i-1][j][0][0] + DP[i][j-1][0][0];
                DP[i][j][0][0] %= mod;
            }
            
            //l is the number of arcades visited
            for(int l = 1; l <= k; l++){
                //Current space is not an arcade
                if(a[i][j] == -1){
                    //For every previous arcade possible, calculate possibilities
                    for(int q = 0; q < k; q++){
                        DP[i][j][q][l] += DP[i-1][j][q][l] + DP[i][j-1][q][l];
                        DP[i][j][q][l] %= mod;
                    }
                }
                else{
                    int num = a[i][j];
                    //Add the arcade as new
                    if(l == 1){
                        DP[i][j][num][l] += DP[i-1][j][0][0] + DP[i][j-1][0][0];
                        DP[i][j][num][l] %= mod;
                    }
                    //Add the arcade into a chain
                    //Since arcade number must increase, use all possible values of previous arcades that has 1 length less
                    else{
                        for(int q = 0; q < num; q++){
                            DP[i][j][num][l] += DP[i-1][j][q][l-1] + DP[i][j-1][q][l-1];
                            DP[i][j][num][l] %= mod;
                        }
                    }
                }
            }
        }
    }

    vector<int> ans(k+1);
    //Sum and print answer for each number of arcade
    for(int i = 0; i <= k; i++){
        //Must include 0 as well...
        for(int j = 0; j <= max(1, k); j++){
            ans[i] += DP[n][m][j][i];
            ans[i] %= mod;
        }
        cout << ans[i] << " ";
    }
    

}
