//Playing with friends whole day
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int n;
    cin >> n;

    for(int i = 0; i < n+2; i++) cout << "@";
    cout << "\n";
    for(int i = 1; i < n + 1; i++){
        for(int j = 0; j < n+2; j++){
            if(j == 0 || j == n+1) cout << "@";
            else cout << " ";
        }
        cout << "\n";
    }
    for(int i = 0; i < n+2; i++) cout << "@";
    cout << "\n";

}
