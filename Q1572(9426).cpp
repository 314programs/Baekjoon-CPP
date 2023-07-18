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

const int MAX = 1e7;
const int V = 65535;
int tree[MAX];
vector<int> a;

void add_element(int node, int s, int e, int val, int diff){
	if(s == e){
		tree[node] += diff;
	}
	else{
		int mid = (s+e)/2;
		if(val <= mid){
			add_element(node*2, s, mid, val, diff);
		}
		else{
			add_element(node*2 + 1, mid+1, e, val, diff);
		}
		tree[node] = tree[node*2] + tree[node*2 + 1];
	}
}

int query(int node, int s, int e, int val){
	if(s == e){
		return s;
	}
	
	int mid = (s+e)/2;
	if(val <= tree[node*2]){
		return query(node*2, s, mid, val);
	}
	else{
		return query(node*2 + 1, mid+1, e, val - tree[node*2]);
	}
}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);
	
	int n, k;
	cin >> n >> k;
	a.resize(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	for(int i = 0; i < k-1; i++){
		add_element(1, 0, V, a[i], 1);
	}

	int ans = 0;	
	for(int i = k-1; i < n; i++){
		add_element(1, 0, V, a[i], 1);
		ans += query(1, 0, V, (k+1)/2);
		add_element(1, 0, V, a[i-(k-1)], -1);
		
	}
	cout << ans;

}
