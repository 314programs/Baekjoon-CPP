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
	while(true){
		int n;
		cin >> n;
		if(n == 0) break;
		cout << cnt << ". ";

		int n1 = 3*n;
		int n2;
		if(n1%2 != 0){
			cout << "odd ";
			n2 = (n1+1)/2;
		}
		else{
			cout << "even ";
			n2 = n1/2;
		}

		int n3 = n2*3;
		int n4 = n3/9;
		cout << n4 << "\n";
		cnt++;

	}

}
