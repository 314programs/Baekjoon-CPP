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

int parent[10001];
int vals[10001];
struct node{
	int weight, a, b;
};

bool compare(const node &u, const node &v){
	return u.weight < v.weight;
}

int find_parent(int target){
	if(parent[target] == target) return target;
	parent[target] = find_parent(parent[target]);
	return parent[target];
}

void union_(int a, int b){
	a = find_parent(a);
	b = find_parent(b);

	if(vals[a] > vals[b]){
		parent[b] = a;
	}
	else{
		parent[a] = b;
	}
}

int32_t main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	vector<int> factory(k);
	vector<node> connections(m);

	memset(vals, 0, sizeof(vals));
	for(int i = 0; i < k; i++){
		cin >> factory[i];
		vals[factory[i]] = 1;
	}

	for(int i = 1; i <= n; i++){
		parent[i] = i;
	}

	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		connections[i] = {c, a, b};
	}
	sort(connections.begin(), connections.end(), compare);

	int ans = 0;
	for(int i = 0; i < m; i++){
		bool build_a = true;
		bool build_b = true;
		for(int j = 0; j < k; j++){
			if(find_parent(connections[i].a) == factory[j]){
				build_a = false;
			}
			if(find_parent(connections[i].b) == factory[j]){
				build_b = false;
			}
		}

		if((build_a || build_b) && find_parent(connections[i].a) != find_parent(connections[i].b)){
			union_(connections[i].a, connections[i].b);
			ans += connections[i].weight;
		}

	}


	cout << ans;
}
