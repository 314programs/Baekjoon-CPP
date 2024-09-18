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

int power(int a, int b, int mod){
    if(b == 0){
        return 1;
    }
    else if(b == 1){
        return a%mod;
    }

    else if(b%2 == 0){
        int temp = power(a, b/2, mod);
        return (temp * temp)%mod;
    }
    else{
        return (a * power(a, b-1, mod))%mod;
    }
}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	float h, w;
	cin >> h >> w;
	cout << fixed << setprecision(1) << h * w * 0.5;

}
