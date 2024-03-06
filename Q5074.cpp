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
		string a, b;
		cin >> a >> b;
		if(a == "00:00" && b == "00:00") break;

		int c = stoll(a.substr(0, 2));
		int d = stoll(a.substr(3, 4));
		int e = stoll(b.substr(0, 2));
		int f = stoll(b.substr(3, 4));
		int add = (d+f)/60;
		
		string hour = to_string((c+e+add)%24);
		string min = to_string((d+f)%60);
		if(hour.length() == 1){
			hour = "0"+hour;
		}
		if(min.length() == 1){
			min = "0"+min;
		}

		cout << hour << ":" << min;
		if((c+e+add)/24 != 0){
			cout << " " << "+" << (c+e+add)/24;
		}
		cout << "\n";

	}

}
