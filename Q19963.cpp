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

int32_t main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

	int n, a, b;
	cin >> n >> a >> b;
	vector<int> lis(n);
	for(int i = 0; i < n; i++){
		lis[i] = i+1;
 	}
	for(int i = 0; i < a; i++){
		int num;
		cin >> num;
		lis[num-1] = -1;
	}
	for(int i = 0; i < b; i++){
		int num;
		cin >> num;
		lis[num-1] = -1;
	}
	cout << n - a - b << "\n";
	for(auto ch: lis){
		if(ch != -1){
			cout << ch << " ";
		}
	}
	

}
