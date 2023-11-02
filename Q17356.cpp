#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    float a, b;
    cin >> a >> b;

    cout << fixed << setprecision(7) << 1.0/(pow(10.0, ((b-a)/400)) + 1.0);

}
