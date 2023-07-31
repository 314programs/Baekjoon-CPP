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

int n;
vector<int> edge[105];
vector<int> rev_edge[105];
bool visited[105];

stack<int> s;
int component[105];
vector<int> components[105];
int num_components;

void dfs1(int x){
	visited[x] = true;
	for(auto ch: edge[x]){
		if(!visited[ch]){
			dfs1(ch);
		}
	}
	s.push(x);
}

void dfs2(int x){
	components[num_components].push_back(x);
	visited[x] = true;

	for(auto ch: rev_edge[x]){
		if(!visited[ch]){
			dfs2(ch);
		}
	}
}

void Kosaraju(){
	memset(visited, false, sizeof(visited));
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			dfs1(i);
		}
	}

	memset(visited, false, sizeof(visited));

	while(!s.empty()){
		int v = s.top();
		s.pop();

		if(!visited[v]){
			dfs2(v);
			num_components++;
		}
	}

}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	cin >> n;
	vector<int> cost(n);
	for(int i = 0; i < n; i++){
		cin >> cost[i];
	}

	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		for(int j = 0; j < n; j++){
			if(s[j] == '1'){
				edge[i].push_back(j);
				rev_edge[j].push_back(i);
			}
		}
	}

	Kosaraju();
	int ans = 0;
	for(int i = 0; i < num_components; i++){
		int cur_cost = 1e9;
		for(auto &ch: components[i]){
			cur_cost = min(cur_cost, cost[ch]);
		}
		ans += cur_cost;
	}
	cout << ans;

}
