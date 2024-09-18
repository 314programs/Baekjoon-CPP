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

	vector<int> small = {0,0,0,0,0,0,0};
	vector<int> big = {0,0,0,0,0,0,0};
	int n;
	string s;
	cin >> n >> s;

	for(auto ch: s){
		if(ch == 'r') small[0]++;
		else if(ch == 'o') small[1]++;
		else if(ch == 'y') small[2]++;
		else if(ch == 'g') small[3]++;
		else if(ch == 'b') small[4]++;
		else if(ch == 'i') small[5]++;
		else if(ch == 'v') small[6]++;

		else if(ch == 'R') big[0]++;
		else if(ch == 'O') big[1]++;
		else if(ch == 'Y') big[2]++;
		else if(ch == 'G') big[3]++;
		else if(ch == 'B') big[4]++;
		else if(ch == 'I') big[5]++;
		else if(ch == 'V') big[6]++;
	}

	bool small_can = true;
	for(auto ch: small){
		if(ch == 0){
			small_can = false;
		}
	}

	bool big_can = true;
	for(auto ch: big){
		if(ch == 0){
			big_can = false;
		}
	}

	if(small_can && big_can){
		cout << "YeS";
	}
	else if(small_can){
		cout << "yes";
	}
	else if(big_can){
		cout << "YES";
	}
	else{
		cout << "NO!";
	}

} 
