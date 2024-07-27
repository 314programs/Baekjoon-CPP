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
	
	int cnt = 1;
	string months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

	while(true){
		int tc;
		cin >> tc;
		if(tc == 0) break;

		map<int, int> m;
		for(int i = 0; i < tc; i++){
			int day, month, year;
			cin >> day >> month >> year;
			m[month]++;
		}
		cout << "Case #" << cnt++ << ":\n";
		for(int i = 1; i <= 12; i++){
			cout << months[i-1] << ":" << string(m[i], '*') << "\n";
		}
	}

} 
