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

int n, m;
vector<int> edge[10005];
vector<int> rev_edge[10005];
bool visited[10005];

stack<int> s;
int component[100005];
vector<int> components[10005];
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
	component[x] = num_components;
	components[num_components].push_back(x);
	visited[x] = true;

	for(auto ch: rev_edge[x]){
		if(!visited[ch]){
			dfs2(ch);
		}
	}
}

void Kosaraju(){
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

	cin >> n >> m;

	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		rev_edge[b].push_back(a);
	}

	Kosaraju();
	cout << num_components-1 << "\n";
	vector<vector<int>> ans;
	for(int i = 0; i < num_components-1; i++){
		sort(components[i].begin(), components[i].end());
		ans.push_back(components[i]);
	}
	sort(ans.begin(), ans.end());

	for(auto ch: ans){
		for(auto x: ch){
			cout << x << " ";
		}
		cout << "-1\n";
	}


}
