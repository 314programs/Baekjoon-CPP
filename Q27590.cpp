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

	int s1, s2;
	int m1, m2;
	cin >> s1 >> s2 >> m1 >> m2;

	int sun_year = s2 - s1;
	int moon_year = m2 - m1;
	int cur = 0;
	while(true){
		if(sun_year == 0 && moon_year == 0) break;
		else if(sun_year == 0) sun_year = s2;
		else if(moon_year == 0) moon_year = m2;

		sun_year--;
		moon_year--;
		cur++;
	}
	cout << cur;

}
