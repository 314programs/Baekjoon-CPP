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

int smaller_val(vector<int> &a, int x, int y){
	if(a[x] == a[y]){
		if(x < y) return x;
		else return y;
	}
	else{
		if(a[x] < a[y]) return x;
		else return y;
	}
}

void init(vector<int> &tree, vector<int> &a, int node, int start, int end){
	if(start == end){
		tree[node] = start;
	}
	else{
		init(tree, a, node*2, start, (start+end)/2);
		init(tree, a, (node*2) + 1, ((start+end)/2) + 1, end);
		tree[node] = smaller_val(a, tree[node*2], tree[node*2 + 1]);
	}
}

void update(vector<int> &tree, vector<int> &a, int change_idx, int change_num, int node, int start, int end){
	if(start > change_idx || end < change_idx || start == end) return;

	update(tree, a, change_idx, change_num, node*2, start, (start+end)/2);
	update(tree, a, change_idx, change_num, (node*2) + 1, ((start+end)/2)+1, end);
	tree[node] = smaller_val(a, tree[node*2], tree[(node*2) + 1]);
}

int32_t main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> a(n+1);

	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	int h = (int) ceil(log2(n));
	int tree_size = (1 << (h+1));
	vector<int> tree(tree_size);
	init(tree, a, 1, 1, n);

	int m;
	cin >> m;
	while(m--){
		int c;
		cin >> c;
		if(c == 1){
			int x, y;
			cin >> x >> y;
			a[x] = y;
			update(tree, a, x, y, 1, 1, n);
		}
		else{
			cout << tree[1] << "\n";
		}
	}


}
