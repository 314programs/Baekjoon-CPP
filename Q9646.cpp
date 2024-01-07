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


int graph[9][9];
int a[9];
int n, k;
int ans;

void solve(int y, int x){
	if(y == 1 && x > a[1]){
		ans++;
		return;
	}

	int left = graph[y][x-1];
	int up = graph[y-1][x];

	for(int i = max(up + 1, left); i <= n; i++){
		graph[y][x] = i;
		if(x <= a[y+1]) solve(y+1, x);
		else solve(1, x+1);
	}
	return;
}


int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	while(cin >> k){
		ans = 0;
		fill(&graph[0][0], &graph[8][8], 0);
		fill(&a[0], &a[8], 0);

		for(int i = 1; i <= k; i++){
			cin >> a[i];
		}
		cin >> n;
		solve(1, 1);
		cout << ans << '\n';
	}

}
