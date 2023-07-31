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
vector<int> edge[200005];
vector<int> rev_edge[200005];
bool visited[200005];

stack<int> s;
int component_num;

void dfs1(int node){
	visited[node] = true;
	for(auto ch: edge[node]){
		if(!visited[ch]){
			dfs1(ch);
		}
	}
	s.push(node);
}

void dfs2(int node){
	visited[node] = true;
	for(auto ch: rev_edge[node]){
		if(!visited[ch]){
			dfs2(ch);
		}
	}
}

void korasaju(){
	memset(visited, false, sizeof(visited));
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			dfs1(i);
		}
	}

	memset(visited, false, sizeof(visited));
	while(!s.empty()){
		int cur = s.top();
		s.pop();

		if(!visited[cur]){
			dfs2(cur);
			component_num++;
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

	korasaju();
	if(component_num == 1){
		cout << "Yes";
	}
	else{
		cout << "No";
	}

}
