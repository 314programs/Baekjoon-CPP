//Incoming math test...
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while(true){
        int n;
        cin >> n;
        if(n == 0) break;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){
                cout << '*';
            }
            cout << "\n";
        }

    }

}
