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

string format[4][6];

int32_t main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
	cin >> n >> m;

	vector<int> a(m);
	for(int i = 0; i < m; i++){
		cin >> a[i];
	}

	int max = 0;
	vector<string> ans;
	int total = m*2 + 1;
	cout << total << "\n";
	cout << "U 1 -1\n";

	for(auto ch: a){
		cout << "U " << 1+ch << " " << ++max << "\n";
		cout << "P\n";
	}

}
