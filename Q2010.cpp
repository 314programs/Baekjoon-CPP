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

	setIO("");

    int n;
    cin >> n;

    int ans = 0;
    int num;
    for(int i = 0; i < n; i++){
        cin >> num;
        ans += num-1;
    }
    cout << ans + 1;

}
