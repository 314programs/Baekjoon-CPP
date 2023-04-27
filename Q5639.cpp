#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long

int a[10001];

void setIO(string s = ""){
	if(s == "") return;
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}

void recurse(int left, int right){
    if(left >= right) return;
    int root = a[left];
    int mid = upper_bound(a + left + 1, a + right, root) - a;
    recurse(left+1, mid);
    recurse(mid, right);
    cout << root << "\n";
}
 
int32_t main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);
 
	setIO();

    int n = 0, idx = 0;
	while(cin >> n){
        a[idx] = n;
        idx++;
    }
    recurse(0, idx);
 
}
