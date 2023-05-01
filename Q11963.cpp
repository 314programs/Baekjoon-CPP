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

	int n;
	cin >> n;
	vector<int> a;
	vector<int> a_;
	set<int> s;
	vector<int> b;
	vector<int> c;

	for(int i = 0; i < n; i++){
		int num;
		cin >> num;

		if(a.size() < n/2){
			a.push_back(num);
		}
		else{
			a_.push_back(num);
		}
		s.insert(num);
	}
	sort(a.begin(), a.end());
	sort(a_.begin(), a_.end());

	for(int i = 1; i <= n*2; i++){
		if(s.count(i) == 0){
			if(b.size() < n/2){
				b.push_back(i);
			}
			else{
				c.push_back(i);
			}
		}
	}

	int i = 0, j = 0;
	int ans = 0;
	while(i < n/2 && j < n/2){
		if(a[i] < c[j]){
			ans++;
			i++;
		}
		j++;
	}

	i = 0, j = 0;
	while(i < n/2 && j < n/2){
		if(a_[i] > b[j]){
			ans++;
			j++;
		}
		i++;
	}
	cout << ans;

}
