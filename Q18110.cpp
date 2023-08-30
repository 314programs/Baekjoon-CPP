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

int visited[1005][1005];

int32_t main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int exclude = round((float)n*0.15);
    int mean = 0;
    int cnt = 0;
    for(int i = exclude; i < n - exclude; i++){
        mean += a[i];
        cnt++;
    }

    if(cnt != 0){
        cout << round((float)mean/cnt);
    }
    else{
        cout << 0;
    }


}
