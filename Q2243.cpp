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

int tree[3000000];

void update(int node, int s, int e, int val, int diff){
	if(s == e){
		tree[node] += diff;
		return;
	}

	int mid = (s+e)/2;
	if(val <= mid){
		update(node*2, s, mid, val, diff);
	}
	else{
		update(node*2 + 1, mid+1, e, val, diff);
	}
	tree[node] = tree[node*2] + tree[node*2 + 1];
}

int query(int node, int s, int e, int idx){
	if(s == e){
		return s;
	}
	
	int mid = (s+e)/2;
	if(idx <= tree[node*2]){
		return query(node*2, s, mid, idx);
	}
	else{
		return query(node*2 + 1, mid+1, e, idx-tree[node*2]);
	}
}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);
	
	int n;
	cin >> n;
	memset(tree, 0, sizeof(tree));

	while(n--){
		int a;
		cin >> a;
		if(a == 1){
			int b;
			cin >> b;
			int ans = query(1, 1, 1000000, b);
			cout << ans << "\n";
			update(1, 1, 1000000, ans, -1);
		}
		else{
			int b, c;
			cin >> b >> c;
			update(1, 1, 1000000, b, c);
		}
	}


}
