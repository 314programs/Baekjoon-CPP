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
 
    int n, m;
    cin >> n >> m;

    int const inf = 1e9;
    int a[n+1][n+1];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            a[i][j] = inf;
        }
    }

    for(int i = 0; i < m; i++){
        int c, d;
        cin >> c >> d;
        a[d][c] = 1;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(k == i || i == j || k == j) continue;
                if(a[i][j] > a[i][k] + a[k][j] && a[i][k] != inf && a[k][j] != inf){
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            if(a[i][j] == inf && a[j][i] == inf) cnt++;
        }
        cout << cnt << "\n";
    }

}
