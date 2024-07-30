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

bool check(string a, string b){
    int cnt = 0;
    int n = a.length();
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]) cnt++;
    }
    if(cnt == 1) return true;
    else return false;
}

int32_t main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);
 
	setIO();

    int w = 0, l = 0;
    for(int i = 0; i < 6; i++){
        char c;
        cin >> c;
        if(c == 'W') w++;
        else l++;
    }

    if(w == 6 || w == 5){
        cout << 1;
    }
    else if(w == 4 || w == 3){
        cout << 2;
    }
    else if(w == 2 || w == 1){
        cout << 3;
    }
    else{
        cout << -1;
    }

}
