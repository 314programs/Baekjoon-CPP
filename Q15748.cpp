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

struct grass{
	int pos, taste;
};

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	int L, n, r_f, r_b;
	cin >> L >> n >> r_f >> r_b;

	vector<grass> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i].pos >> a[i].taste;
	}

	sort(a.begin(), a.end(), [&](grass &u, grass &v){
		return u.taste > v.taste;
	});

	int fj_d = 0;
	int bs_d = 0;
	int ans = 0;
	int cur_idx = 0;

	while(fj_d <= L){
		while(a[cur_idx].pos <= bs_d && cur_idx != n){
			cur_idx++;
		}
		if(cur_idx == n) break;

		int bs_t = (a[cur_idx].pos - bs_d) * r_b;
		int fj_t = (a[cur_idx].pos - fj_d) * r_f;
		ans += (fj_t - bs_t) * a[cur_idx].taste;
		fj_d = bs_d = a[cur_idx].pos;

	}

	cout << ans;

}
