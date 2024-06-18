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

vector<int> graph[51];
int ans = 0;

void dfs(int cur, int m, int root){
	if(cur == m) return;

	int cnt = 0;
	bool has_m = false;
	for(auto ch: graph[cur]){
		if(ch != m){
			dfs(ch, m, root);
			cnt++;
		}
	}

	if(cnt == 0){
		ans++;
	}
}

int32_t main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

	int n;
	cin >> n;
	int root = -1;

	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		if(num != -1){
			graph[num].push_back(i);
		}
		else{
			root = i;
		}
	}
	int m;
	cin >> m;
	dfs(root, m, root);
	cout << ans;

}
