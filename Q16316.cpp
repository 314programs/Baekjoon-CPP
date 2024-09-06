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
	int cnt = 1;
	int can = true;
	for(int i = 0; i < n; i++){
		string num;
		cin >> num;
		if(num != "mumble" && stoll(num) != cnt){
			can = false;
		}
		cnt++;
	}
	if(can) cout << "makes sense";
	else cout << "something is fishy";

} 
