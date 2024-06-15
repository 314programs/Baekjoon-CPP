#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

long long gdc(ll a, ll b){
    if(b == 0) return a;
    return gdc(b, a%b);
}

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    ll a, b;
    cin >> a >> b;

    int factor = gdc(a, b);
    //This is a good code to remember when I want a repeated string
    cout << string(factor, '1');

}
