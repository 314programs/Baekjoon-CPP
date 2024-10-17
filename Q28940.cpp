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

	int w, h;
	int n, a, b;
	cin >> w >> h >> n >> a >> b;

	if(a > w || b > h){
		cout << -1;
	}
	else{
		int perPage = (w/a) * (h/b);
		cout << ceil((float) n / (float) perPage);
	}

}
