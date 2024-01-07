//I felt like I wanted to work more on my game today so I picked a easy segtree
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

vector<int> tree;

void update(int node, int s, int e, int idx, int diff){
	if(s > idx || idx > e) return;
	if(s == e){
		tree[node] += diff;
		return;
	}

	int mid = (s+e)/2;
	update(node*2, s, mid, idx, diff);
	update(node*2 + 1, mid+1, e, idx, diff);
	tree[node] = tree[node*2] + tree[node*2+1];
}

int sum(int node, int s, int e, int left, int right){
	if(left > e || right < s) return 0;
	if(s >= left && e <= right){
		return tree[node];
	}

	int mid = (s+e)/2;
	return sum(node*2, s, mid, left, right) + sum(node*2+1, mid+1, e, left, right);
}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	tree.resize(n*4 + 20);

	while(m--){
		int a, b, c;
		cin >> a >> b >> c;
		if(a == 1){
			update(1, 1, n, b, c);
		}
		else{
			cout << sum(1, 1, n, b, c) << "\n";
		}
	}


}
