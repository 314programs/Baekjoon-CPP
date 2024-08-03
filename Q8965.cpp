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

bool visited[100005];

int32_t main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int n = s.length();

		vector<string> a;
		for(int i = 0; i < n; i++){
			a.push_back(s.substr(i, n) + s.substr(0, i));
		}
		sort(a.begin(), a.end());
		cout << a[0] << "\n";
	}

}
