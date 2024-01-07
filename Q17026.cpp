#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long

struct peak{
	int start, end;
};

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

	//USACO Input
	/*
	fstream cin;
	cin.open("");
	ofstream cout;
	cout.open("");
	*/
	///////////////////////////////////////////////////////////////////////////////

    int n;
	cin >> n;

	vector<peak> a(n);
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		a[i] = {x-y, x+y};
	}
	sort(a.begin(), a.end(), [&](peak &u, peak &v){
		if(u.start == v.start) return u.end > v.end;
		return u.start < v.start;
	});

	int right = -1;
	int visible = 0;
	for(auto ch: a){
		if(ch.end > right){
			visible++;
			right = ch.end;
		}
	}
	cout << visible;

}
