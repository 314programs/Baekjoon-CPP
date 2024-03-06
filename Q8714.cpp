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
	
	int one_cnt = 0, zero_cnt = 0;
	while(n--){
		int num;
		cin >> num;
		if(num == 1) one_cnt++;
		else zero_cnt++;
	}
	cout << min(zero_cnt, one_cnt);

}
