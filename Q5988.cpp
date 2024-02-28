//This question got me with the range of data given...

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
	cin.tie(NULL), std::cout.tie(NULL);

	setIO("");

	int tc;
	cin >> tc;

	while(tc--){
		string s;
		cin >> s;
		if((s.back()-'0')%2 == 0) cout << "even\n";
		else cout << "odd\n";
	}

}
