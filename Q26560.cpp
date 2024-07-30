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
	
	int tc;
	cin >> tc;
	cin.ignore();
	while(tc--){
		string s;
		getline(cin, s);
		if(s[s.length()-1] == '.'){
			cout << s << "\n";
		}
		else{
			cout << s << ".\n"; 
		}
	}

}
