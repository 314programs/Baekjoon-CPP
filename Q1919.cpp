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

	string a, b;
	cin >> a >> b;
	map<char, int> m_a;
	map<char, int> m_b;

	for(auto ch: a){
		m_a[ch]++;
	}
	for(auto ch: b){
		m_b[ch]++;
	}

	int cnt = 0;
	for(int i = 97; i <= 122; i++){
		cnt += abs(m_a[(char)i] - m_b[(char)i]);
	}
	cout << cnt;

}
