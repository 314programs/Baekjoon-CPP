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
		string s;
		int n;
		cin >> s >> n;
		cout << s << " ";
		if(n >= 97){
			cout << "A+\n";
		}
		else if(n >= 90){
			cout << "A\n";
		}
		else if(n >= 87){
			cout << "B+\n";
		}
		else if(n >= 80){
			cout << "B\n";
		}
		else if(n >= 77){
			cout << "C+\n";
		}
		else if(n >= 70){
			cout << "C\n";
		}
		else if(n >= 67){
			cout << "D+\n";
		}
		else if(n >= 60){
			cout << "D\n";
		}
		else{
			cout << "F\n";
		}
	}

}
