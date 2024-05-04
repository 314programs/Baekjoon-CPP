//C++ rounding acting weird?

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int cur, want, k;
    cin >> cur >> want >> k;

    if((want-cur)%k == 0){
        cout << (want-cur)/k;
    }
    else{
        cout << 1+((want-cur)/k);
    }

}
