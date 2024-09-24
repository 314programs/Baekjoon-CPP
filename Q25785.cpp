//Lazy code
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

	string s;
	cin >> s;

	int yes = 1;
	for(int i = 0; i < s.length(); i++){
		if(i%2 == 0){
			if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
				yes = 0;
				break;
			}
		}
		else{
			if(!(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')){
				yes = 0;
				break;
			}
		}
	}

	int yes2 = 1;
	for(int i = 0; i < s.length(); i++){
		if(i%2 == 1){
			if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
				yes2 = 0;
				break;
			}
		}
		else{
			if(!(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')){
				yes2 = 0;
				break;
			}
		}
	}


	if(yes2 != 0 || yes != 0) cout << 1;
	else cout << 0;
	

} 
