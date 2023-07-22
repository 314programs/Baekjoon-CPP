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

int h[1000010];
vector<int> arr, tree;

void update(int node, int s, int e, int idx, int diff){
	if(s > idx || idx > e) return;
	tree[node] += diff;

	if(s != e){
		int mid = (s+e)/2;
		update(node*2, s, mid, idx, diff);
		update(node*2 + 1, mid+1, e, idx, diff);
	}
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

	int n;
	cin >> n;
	arr.resize(n + 10);
	tree.resize(n*4 + 10);

	for(int i = 1; i <= n; i++){
		int num;
		cin >> num;
		h[num] = i;
	}
	for(int i = 1; i <= n; i++){
		int num;
		cin >> num;
		arr[i] = h[num];
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++){
		int j = arr[i];
		ans += sum(1, 1, n, j+1, n);
		update(1, 1, n, j, 1);
	}
	cout << ans;


}
