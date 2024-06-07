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

	int a = 0;
	int b = 0;
	int c = 0;

	if(n <= 2){
		cout << "0\n3";
	}
	else{
		int cnt = 0;
		int tri = 0;
		for(int i = 1; i <= n-2; i++){
			cnt += i;
			tri += cnt;
		}
		cout << tri << "\n3";
	}
	

}
