#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
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

    int n, m;
    cin >> n >> m;
    vector<int> a, b;

    for(int i = 1; i <= n; i++){
        if(n%i == 0){
            a.push_back(i);
        }
    }

    for(int i = 1; i <= m; i++){
        if(m%i == 0){
            b.push_back(i);
        }
    }

    int a_len = a.size();
    int b_len = b.size();
    for(int i = 0; i < a_len; i++){
        for(int j = 0; j < b_len; j++){
            cout << a[i] << " " << b[j] << "\n";
        }
    }

}
