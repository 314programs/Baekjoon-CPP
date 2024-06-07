#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int tc;
    cin >> tc;

    int l, w;
    cin >> l >> w;

    while(tc--){
        int num;
        cin >> num;

        if(num <= floor(sqrt(pow(l, 2) + pow(w, 2)))){
            cout << "DA\n";
        }
        else{
            cout << "NE\n";
        }

    }

}
