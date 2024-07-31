#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
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

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int num;
        cin >> num;
        cout << "Case #" << i << ": ";
        if(num <= 25){
            cout << "World Finals\n";
        }
        else if(num > 25 && num <= 1000){
            cout << "Round 3\n";
        }
        else if(num > 1000 && num <= 4500){
            cout << "Round 2\n";
        }
        else{
            cout << "Round 1\n";
        }
    }

}
