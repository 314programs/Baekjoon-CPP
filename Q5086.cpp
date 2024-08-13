#include <bits/stdc++.h>
using namespace std;

//Might do proper DP later
//Had a nap because I was tired
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while(true){
        int a, b;
        cin >> a >> b;
        if(a == 0) break;

        if(b%a == 0){
            cout << "factor\n";
        }
        else if(a%b == 0){
            cout << "multiple\n";
        }
        else{
            cout << "neither\n";
        }

    }

}
