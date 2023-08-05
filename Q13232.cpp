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

vector<int> edge[5005];
vector<int> rev_edge[5005];
stack<int> s;
bool visited[5005];

int n, m;
int num_components = 0;
vector<int> components[5005];


void dfs_1(int cur){
	visited[cur] = true;
	for(auto ch: edge[cur]){
		if(!visited[ch]){
			dfs_1(ch);
		}
	}
	s.push(cur);
}

void dfs_2(int cur){
	components[num_components].push_back(cur);
	visited[cur] = true;

	for(auto ch: rev_edge[cur]){
		if(!visited[ch]){
			dfs_2(ch);
		}
	}
	
}

void korasaju(){
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			dfs_1(i);
		}
	}

	memset(visited, false, sizeof(visited));
	while(!s.empty()){
		int cur = s.top();
		s.pop();

		if(!visited[cur]){
			dfs_2(cur);
			num_components++;
		}
	}

}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	cin >> n >> m;

	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		rev_edge[b].push_back(a);
	}

	memset(visited, false, sizeof(visited));
	korasaju();

	int ans = 0;
	for(int i = 0; i < num_components; i++){
		ans = max(ans, (int)components[i].size());
	}
	cout << ans;

}
