//Resting
#include <bits/stdc++.h>
using namespace std;


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string can;
    string want;

    getline(cin, can);
    getline(cin, want);

    if(can.length() >= want.length()){
        cout << "go";
    }
    else{
        cout << "no";
    }

}
