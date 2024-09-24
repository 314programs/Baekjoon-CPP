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

	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	int cur_h = a[0];
	int max_score = 0;
	int cur_score = 0;

	for(int i = 1; i < n; i++){
		if(a[i] > cur_h){
			cur_h = a[i];
			max_score = max(max_score, cur_score);
			cur_score = 0;
		}
		else{
			cur_score++;
		}
	}
	max_score = max(max_score, cur_score);
	cout << max_score;


} 
