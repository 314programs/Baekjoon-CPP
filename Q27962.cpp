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

    int n;
    cin >> n;

    string s;
    cin >> s;
    string ans = "NO";
    
    //Mistook 1 >= as 1 > 
    for(int i = 1; i <= n-1; i++){
        string a = s.substr(0, i);
        string b = s.substr(n-i, i);
        if(check(a, b)){
            ans = "YES";
        }
    }
    cout << ans;

}
