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

	int student[7][2];
	int n, k;
	cin >> n >> k;

	int ans = 0;
	memset(student, 0, sizeof(student));

	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		student[b][a]++;
	}

	for(int i = 1; i < 7; i++){
		for(int j = 0; j <= 1; j++){
			if(student[i][j] != 0){
				ans += (student[i][j] + (k-1))/k;
			}
		}
	}
	cout << ans;

}
