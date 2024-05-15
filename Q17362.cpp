//Why was this lowkey hard
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int n;
    cin >> n;

    if(n%8 == 1){
        cout << 1;
    }
    else if(n%8 == 2 || n%8 == 0){
        cout << 2;
    }
    else if(n%8 == 7 || n%8 == 3){
        cout << 3;
    }
    else if(n%8 == 4 || n%8 == 6){
        cout << 4;
    }
    else{
        cout << 5;
    }


}
