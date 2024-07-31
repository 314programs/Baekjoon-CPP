//Math test incoming

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int m, n;
    cin >> m >> n;

    if(n <= 2){
        cout << "NEWBIE!";
    }
    else if(n <= m){
        cout << "OLDBIE!";
    }
    else{
        cout << "TLE!";
    }


}
