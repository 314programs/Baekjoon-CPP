//Seg recap
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

void init(vector<int> &tree, vector<int> &a, int node, int start, int end){
    if(start == end){
        tree[node] = (a[start]%2 == 0) ? 1:0;
    }
    else{
        init(tree, a, node*2, start, (start+end)/2);
        init(tree, a, (node*2)+1, ((start+end)/2) + 1, end);
        tree[node] = tree[(node*2)+1] + tree[node*2];
    }
}

void update(vector<int> &tree, int change_i, int change_num, int node, int start, int end){
    if(start > change_i || end < change_i) return;
    if(start == end){
        tree[node] = (change_num%2 == 0) ? 1:0;
        return;
    }

    update(tree, change_i, change_num, node*2, start, (start+end)/2);
    update(tree, change_i, change_num, (node*2)+1, ((start+end)/2)+1, end);
    tree[node] = tree[node*2] + tree[(node*2)+1];
}

int query(vector<int> &tree, int node, int start, int end, int i, int j){
    if(start > j || end < i) return -1;
    if(start >= i && end <= j) return tree[node];
    
    int n1 = query(tree, node*2, start, (start+end)/2, i, j);
    int n2 = query(tree, (node*2)+1, ((start+end)/2)+1, end, i, j);
    
    if(n1 == -1) return n2;
    else if(n2 == -1) return n1;
    else return n1 + n2;
}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);
	
	int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    //Calculate tree size using log and bitmasking
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));
    vector<int> tree(tree_size);
  
    //Initialise tree
    init(tree, a, 1, 0, n-1);

    int m;
    cin >> m;
    while(m--){
        int c, i, j;
        cin >> c >> i >> j;
		if(c == 1){
			update(tree, i-1, j, 1, 0, n-1);
		}

		else{
			int cur = query(tree, 1, 0, n-1, i-1, j-1);
			if(c == 2){
				cout << cur << "\n";
			}
			else{
				cout << j-i-cur+1 << "\n";
			}
		}
    }

}
