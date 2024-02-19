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

int a[105];

int32_t main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        a[i] = i;
    }

    while(m--){
        int c, d;
        cin >> c >> d;
        swap(a[c], a[d]);
    }

    for(int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }


}
