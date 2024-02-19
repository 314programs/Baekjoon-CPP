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
	while(tc--){
		vector<int> a(3);
		int cnt = 0;
		for(int i = 0; i < 3; i++){
			cin >> a[i];
			if(a[i] >= 10) cnt++;
			cout << a[i] << " ";
		}
		cout << "\n";

		if(cnt == 0) cout << "zilch\n";
		else if(cnt == 1) cout << "double\n";
		else if(cnt == 2) cout << "double-double\n";
		else cout << "triple-double\n";
		cout << "\n";

	}

}
