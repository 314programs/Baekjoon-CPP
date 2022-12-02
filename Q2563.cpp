//Just wanted to do

#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int n;
    cin >> n;
    bool square[100][100];
    memset(square, false, sizeof(square));

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;

        for(int iy = y; iy < 10+y; iy++){
            for(int ix = x; ix < 10+x; ix++){
                square[iy][ix] = true;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(square[i][j]) ans++;
        }
    }
    cout << ans;

}
