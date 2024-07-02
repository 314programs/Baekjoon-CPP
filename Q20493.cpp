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
    cin.tie(NULL), cout.tie(NULL);

	int n, t;
	cin >> n >> t;

	int dir = 4;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, -1, 0, 1};

	vector<int> times(n+2);
	vector<string> turn(n);
	times[0] = 0;
	for(int i = 1; i <= n; i++){
		cin >> times[i] >> turn[i-1];
	}
	times[n+1] = t;
	pair<int, int> coord = make_pair(0, 0);

	for(int i = 0; i < n+1; i++){
		int diff = times[i+1] - times[i];
		int cur_dir = dir%4;
		coord.first += diff * dx[cur_dir];
		coord.second += diff * dy[cur_dir];

		if(i < n){
			if(turn[i] == "right"){
				dir++;
			}
			else{
				dir--;
			}
		}
		if(dir > 8){
			dir -= 4;
		}
		if(dir <= 0){
			dir += 4;
		}
	}
	cout << coord.first << " " << coord.second << "\n";


}
