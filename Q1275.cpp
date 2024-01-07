//the fact that sometimes y < x was evil

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

vector<int> a;
int tree[400000];
void init(int node, int s, int e){
	if(s == e){
		tree[node] = a[s];
	}
	else{
		int mid = (s+e)/2;
		init(node*2, s, mid);
		init(node*2 + 1, mid+1, e);
		tree[node] = tree[node*2] + tree[node*2 + 1];
	}
}

int query(int node, int s, int e, int i, int j){
	if(e < i || s > j) return 0;
	if(s >= i && e <= j){
		return tree[node];
	}

	int mid = (s+e)/2;
	int n1 = query(node*2, s, mid, i, j);
	int n2 = query(node*2 + 1, mid+1, e, i, j);
	return n1 + n2;
}

void update(int node, int s, int e, int idx, int val){
	if(s > idx || e < idx) return;
	if(s == e){
		tree[node] = val;
		return;
	}

	int mid = (s+e)/2;
	update(node*2, s, mid, idx, val);
	update(node*2 + 1, mid+1, e, idx, val);
	tree[node] = tree[node*2] + tree[node*2 + 1];
}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	a.resize(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	init(1, 0, n-1);

	while(m--){
		int i, j;
		cin >> i >> j;
		if(j < i) swap(i, j);
		cout << query(1, 0, n-1, i-1, j-1) << '\n';

		int idx, val;
		cin >> idx >> val;
		update(1, 0, n-1, idx-1, val);
	}


}
