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
	
	while(true){
		vector<int> a(4);
		for(int i = 0; i < 4; i++){
			cin >> a[i];
		}
		if(a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0) break;

		int cnt = 0;
		while(!(a[0] == a[2] && a[0] == a[3] && a[0] == a[1])){
			vector<int> b = {abs(a[0]- a[1]), abs(a[1]- a[2]), abs(a[2]- a[3]), abs(a[3]- a[0])};
			a = b;
			cnt++;
		}
		cout << cnt << "\n";
	}

}
