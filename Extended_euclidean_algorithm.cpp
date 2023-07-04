#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long

void setIO(string s = ""){
	if(s == "") return;
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}

int gcd_ex(int a, int b, int *x, int *y){
    if(a == 0){
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1;
    int gcd = gcd_ex(b%a, a, &x1, &y1);

    *x = y1 - x1*(b/a);
    *y = x1;
    return gcd;

}

int32_t main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int a, b, x, y;
    cin >> a >> b;
    int gcd = gcd_ex(a, b, &x, &y);
    cout << gcd << " " << x << " " << y;

}
