#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

int a[10][10];
int flip[10][10];

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    
    //I should have used boolean to make my life easier...
    memset(flip, 0, sizeof(flip));
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            a[i][j] = s[j] - '0';
        }
    }
    
    //Starting from the right bottom corner, if the cow is tipped mark the rectangle that includes the cow
    //Cows at the outside has to be flipped first
    //The number of flips will be stored indicates if a cow is tipped or not
    int ans = 0;
    for(int i = n-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            if((a[i][j]+flip[i][j])%2 == 1){
                ans++;
                //Update upper left rectangle
                for(int y = 0; y <= i; y++){
                    for(int x = 0; x <= j; x++){
                        flip[y][x]++;
                    }
                }
            }
        }
    }

    cout << ans;
     

}
