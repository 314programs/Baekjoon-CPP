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


int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	setIO("berries");

	int n, k;
	cin >> n >> k;

	vector<int> a(n);
    int mx_d = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
        mx_d = max(a[i], mx_d);
	}

    int mx = 0;
    for(int i = 1; i <= mx_d; i++){
        int amount = 0;
        for(int j = 0; j < n; j++){
            amount += a[j]/i;
        }
        if(amount < k/2) continue;

        if(amount >= k){
            mx = max(mx, (k/2)*i);
            continue;
        }
        sort(a.begin(), a.end(), [&](int &u, int &v){
            return (u%i) > (v%i);
        });

        int cur = (amount-k/2) * i;
        for(int j = 0; j < n && j + amount < k; j++){
            cur += a[j]%i;
        }
        mx = max(mx, cur);
    }
    cout << mx;
	
}
