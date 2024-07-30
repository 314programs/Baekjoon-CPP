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

	int n;
	cin >> n;
	while(n--){
		string s;
		cin >> s;
		int cnt = 0;
		for(auto ch: s){
			if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
				cnt++;
			}
		}
		if(cnt > s.length()-cnt){
			cout << s << "\n" << 1 << "\n";
		}
		else{
			cout << s << "\n" << 0 << "\n";
		}
	}

}
