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

	int m, d;
	cin >> m >> d;

	int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	string days[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

	int day = d;
	for(int i = 1; i < m; i++){
		day += months[i];
	}
	cout << days[day%7];

} 
