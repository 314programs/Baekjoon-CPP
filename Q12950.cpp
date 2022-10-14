#include <bits/stdc++.h>
using namespace std;

//Similar to the nigthmarish question from yesterday... Q2172
//But with less for loops yay

char a[21][21];
//Start, finish
//Shortest palindrome length
int DP[21][21];
int const inf = 1e9;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            a[i][j] = '0';
            DP[i][j] = inf;
        }
        DP[i][i] = 0;
    }

    for(int i = 0; i < m; i++){
        int x, y;
        char c;
        cin >> x >> y >> c;
        a[x][y] = c;
        a[y][x] = c;
        DP[x][y] = 1;
        DP[y][x] = 1;
    }
    
    //Only length of 400 can be made 400 = 20^2
    for(int l = 2; l <= 400; l++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                
                //Path exists
                if(DP[i][j] != inf){
                    for(int i2 = 0; i2 < n; i2++){
                        for(int j2 = 0; j2 < n; j2++){
                            
                            //Path exists and is palindrome
                            if(a[i2][i] != '0' && a[j][j2] != '0'){
                                if(a[i2][i] == a[j][j2]){
                                    DP[i2][j2] = min(DP[i2][j2], DP[i][j] + 2);
                                }
                            }

                        }
                    }
                }
            }
        }
    }

    if(DP[0][1] >= inf) cout << "-1";
    else cout << DP[0][1];

}
