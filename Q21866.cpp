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

	vector<int> scores = {100, 100, 200, 200, 300, 300, 400, 400, 500};
	int total = 0;
	bool cheated = false;
	for(int i = 0; i < 9; i++){
		int num;
		cin >> num;
		if(num > scores[i]){
			cheated = true;
		}
		total += num;
	}

	if(cheated){
		cout << "hacker";
	}
	else{
		if(total >= 100){
			cout << "draw";
		}
		else{
			cout << "none";
		}
	}

}
