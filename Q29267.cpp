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

	int n, k;
	cin >> n >> k;
	int m = 0;
	int save = 0;
	while(n--){
		string s;
		cin >> s;
		if(s == "save"){
			save = m;
		}
		else if(s == "load"){
			m = save;
		}
		else if(s == "shoot"){
			m--;
		}
		else{
			m += k;
		}
		cout << m << "\n";
	}
	

} 
