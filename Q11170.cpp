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
 
    vector<int> a(1000002, 0);
    for(int i = 0; i <= 1000000; i++){
        string cur = to_string(i);
        int cnt = 0;
        for(auto ch: cur){
            if(ch == '0') cnt++;
        }
        a[i+1] = a[i] + cnt;
    }

    int tc;
    cin >> tc;
    while(tc--){
        int n, m;
        cin >> n >> m;
        cout << a[m+1] - a[n] << "\n";
    }

}
