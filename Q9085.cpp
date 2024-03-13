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

struct boot{
	int max_depth, max_step, index;
};

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	setIO("");

	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		int ans = 0;
		while(n--){
			int num;
			cin >> num;
			ans += num;
		}
		cout << ans << endl;
	}

}
