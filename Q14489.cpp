//Quick grass
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    ll a, b;
    cin >> a >> b;

    ll c;
    cin >> c;

    if(a+b >= c*2){
        cout << a+b-(c*2);
    }
    else{
        cout << a+b;
    }

}
