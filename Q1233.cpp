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

    vector<int> lis(100, 0);
    int a, b, c;
    cin >> a >> b >> c;

    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            for(int k = 1; k <= c; k++){
                int cur = i+j+k;
                lis[cur]++;
            }
        }
    }

    int mx = 1;
    int mx_cnt = 0;
    for(int i = 1; i <= a+b+c; i++){
        if(lis[i] > mx_cnt){
            mx_cnt = lis[i];
            mx = i;
        }
    }
    cout << mx;

}
