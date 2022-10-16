#include <bits/stdc++.h>
using namespace std;

int n;
int a[16];
bool DP[81][81][81][81];

//Bruteforce was possible cause 16 sticks is the maximum
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    //Limit for faster time
    int s2 = sum/2;
    int lim1 = s2/2;
    int lim2 = s2-1;

    memset(DP, false, sizeof(DP));

    DP[0][0][0][0] = true;
    for(int i = 0; i < n; i++){
        //Use minus cause plus causes everything to add up...
        for(int l1 = lim1; l1 >= 0; l1--){
            for(int l2 = lim1; l2 >= 0; l2--){
                for(int l3 = lim2; l3 >= 0; l3--){
                    for(int l4 = lim2; l4 >= 0; l4--){
                        if(DP[l1][l2][l3][l4] == false) continue;

                        if(l1 + a[i] <= 80) DP[l1 + a[i]][l2][l3][l4] = true;
                        if(l2 + a[i] <= 80) DP[l1][l2 + a[i]][l3][l4] = true;
                        if(l3 + a[i] <= 80) DP[l1][l2][l3 + a[i]][l4] = true;
                        if(l4 + a[i] <= 80) DP[l1][l2][l3][l4 + a[i]] = true;

                    }
                }
            }
        }
    }

    int ans = -1;
    
    //Find rectangle
    for(int i = 1; i <= 80; i++){
        for(int j = 1; j <= 80; j++){
            if(DP[i][i][j][j] == true){
                ans = max(i*j, ans);
            }
        }
    }
    if(ans > 0) cout << ans;
    else cout << -1;

}
