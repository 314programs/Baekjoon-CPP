#include <bits/stdc++.h>
using namespace std;

int n, L;
int a[20][20];
//Length of palindrome, y1, x1, y2, x2
//(y1, x1) -> (y2, x2)
int DP[21][20][20][20][20];

bool check(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < n);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> L;

    //Palindrome length 1
    memset(DP, 0, sizeof(DP));
    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            cin >> a[y][x];
            DP[1][x][y][x][y] = 1;
        }
    }

    //Palindrome length 2
    //Get starting coordinate
    for(int y1 = 0; y1 < n; y1++){
        for(int x1 = 0; x1 < n; x1++){
            //8 directions
            for(int y2 = y1-1; y2 <= y1+1; y2++){
                for(int x2 = x1-1; x2 <= x1+1; x2++){
                    //Start != end, palindrome and does not go out of graph
                    if(!(x1 == x2 && y1 == y2)){
                        //Made mistake with this part before...
                        //DP was x1, y1, x2, y2... but a was x1 y1...
                        if(a[y2][x2] == a[y1][x1] && check(x2, y2)){
                            DP[2][y1][x1][y2][x2] = 1;
                        }
                    }
                }
            }
        }
    }

    //For each length...
    for(int l = 3; l <= L; l++){
        //Get start and end coordinates
        for(int y1 = 0; y1 < n; y1++){
            for(int x1 = 0; x1 < n; x1++){
                for(int y2 = 0; y2 < n; y2++){
                    for(int x2 = 0; x2 < n; x2++){
                        //Can be outside of palindrome?
                        if(a[y1][x1] == a[y2][x2]){
                            
                            for(int y3 = y1-1; y3 <= y1+1; y3++){
                                for(int x3 = x1-1; x3 <= x1+1; x3++){
                                    for(int y4 = y2-1; y4 <= y2+1; y4++){
                                        for(int x4 = x2-1; x4 <= x2+1; x4++){

                                            //Check if within bounds
                                            if(check(x3, y3) && check(x4, y4)){
                                                if(!(x1 == x3 && y1 == y3) && !(x2 == x4 && y2 == y4)){
                                                    DP[l][y1][x1][y2][x2] += DP[l-2][y3][x3][y4][x4];
                                                }
                                            }

                                        }
                                    }
                                }
                            }

                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int x1 = 0; x1 < n; x1++){
        for(int y1 = 0; y1 < n; y1++){
            for(int x2 = 0; x2 < n; x2++){
                for(int y2 = 0; y2 < n; y2++){
                    ans += DP[L][x1][y1][x2][y2];
                }
            }
        }
    }

    cout << ans;

}
