#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while(true){
        float n;
        cin >> n;
        if(n == 0){
            break;
        }
        n = pow(n, 4) + pow(n, 3) + pow(n, 2) + pow(n, 1) + 1;
        cout << setprecision(2) << fixed << n << "\n";
    }
    

}
