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

	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		int score1 = 0, score2 = 0;
		for(int i = 0; i < n; i++){
			char P1, P2;
			cin >> P1 >> P2;
			if(P1 == 'R' && P2 == 'S'){
				score1++;
			}
			else if(P1 == 'S' && P2 == 'R'){
				score2++;
			}
			else if(P1 == 'S' && P2 == 'P'){
				score1++;
			}
			else if(P1 == 'P' && P2 == 'S'){
				score2++;
			}
			else if(P1 == 'P' && P2 == 'R'){
				score1++;
			}
			else if(P1 == 'R' && P2 == 'P'){
				score2++;
			}
		}

		if(score1 > score2){
			cout << "Player 1\n";
		}
		else if(score1 < score2){
			cout << "Player 2\n";
		}
		else{
			cout << "TIE\n";
		}
	}
    
}
