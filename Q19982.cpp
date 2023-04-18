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
 
	setIO("");

	int n, inf = 2e9;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] *= 2;
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());

    vector<int> dp[2];
    for(int it = 0; it < 2; it++){
        int idx = 0;
        dp[it].resize(n, inf);
        dp[it][0] = -2;

        for(int i = 1; i < n; i++){
            while(idx + 1 < i && abs(a[i] - a[idx + 1]) > dp[it][idx+1] + 2){
                idx++;
            }
            dp[it][i] = min(abs(a[i] - a[idx]), dp[it][idx+1] + 2);
        }
        reverse(a.begin(), a.end());
    }
    reverse(dp[1].begin(), dp[1].end());

    int i = 0;
    int j = n-1;
    int ans = inf;

    while(i < j){
        ans = min(ans, max((a[j]-a[i])/2, 2 + max(dp[0][i], dp[1][j])));
        if(dp[0][i+1] < dp[1][j-1]){
            i++;
        }
        else{
            j--;
        }
    }

    cout << fixed << setprecision(1) << (double)(ans/2.0);

 
}
