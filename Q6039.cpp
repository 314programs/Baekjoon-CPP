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

string format[4][6];

int32_t main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);


	int f, m, n;
	cin >> f >> m >> n;

	vector<int> force(n);
	vector<int> mass(n);
	for(int i = 0; i < n; i++){
		cin >> force[i] >> mass[i];
	}

	double max_a = 0;
	vector<int> ans;

	for(int i = 0; i < (1 << n); i++){
		int cur_force = f;
		int cur_mass = m;
		for(int j = 0; j < n; j++){
			if(i & (1 << j)){
				cur_force += force[j];
				cur_mass += mass[j];
			}
		}
		double cur_a = (double)cur_force/(double)cur_mass;

		if(cur_a > max_a){
			ans.clear();
			max_a = cur_a;
			for(int j = 0; j < n; j++){
				if(i & (1 << j)){
					ans.push_back(j+1);
				}
			}
		}
	}

	if(ans.size() == 0) cout << "NONE";
	else{
		for(auto ch: ans){
			cout << ch << "\n";
		}
	}

}
