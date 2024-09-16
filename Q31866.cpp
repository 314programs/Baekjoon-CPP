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

	int a, b;
	cin >> a >> b;

	if((a == 0 || a == 2 || a == 5) && (b == 0 || b == 2 || b == 5)){
		if((a == 0 && b == 2) || (a == 2 && b == 5) || (a == 5 && b == 0)){
			cout << ">";
		}
		else if((b == 0 && a == 2) || (b == 2 && a == 5) || (b == 5 && a == 0)){
			cout << "<";
		}
		else{
			cout << "=";
		}

	}
	else if(!(a == 0 || a == 2 || a == 5) && (b == 0 || b == 2 || b == 5)){
		cout << "<";
	}
	else if((a == 0 || a == 2 || a == 5) && !(b == 0 || b == 2 || b == 5)){
		cout << ">";
	}
	else{
		cout << "=";
	}
	
} 
