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

int gcd(int a, int b){
    if(a == 0){
        return b;
    }
    return gcd(b%a, a);
}

int ex_gcd(int a, int b, int *x, int *y){
    if(a == 0){
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1;
    int gcd = ex_gcd(b%a, a, &x1, &y1);

    *x = y1 - x1*(b/a);
    *y = x1;
    return gcd;
}

int32_t main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int a, b, c, d, e, f, g;
    cin >> a >> b >> c >> d >> e >> f >> g;

    vector<int> remainders = {c, d, e};
    vector<int> largest;
    int cnt = 0;
    while(true){
        int a_ = a - cnt*2;
        int b_ = b - cnt*2;
        if(a_ <= 0 || b_ <= 0) break;
        largest.push_back(a_ * b_ * cnt++);
    }
    sort(largest.rbegin(), largest.rend());

    int a1 = remainders[0];
    int m1 = largest[0];

    for(int i = 1; i < 3; i++){
        int a2 = remainders[i];
        int m2 = largest[i];
        int g = gcd(m1, m2);

        int x, y;
        ex_gcd(m1/g, m2/g, &x, &y);
        int mod = (m1*m2)/g;

        int ans = (a1*(m2/g)*y + a2*(m1/g)*x);
        a1 = ans;
        while(a1 < 0) a1 += mod;
        m1 = mod;
    }

    while(a1 > g){
        a1 -= m1;
    }
    while(a1 < f){
        a1 += m1;
    }
    cout << a1;

}
