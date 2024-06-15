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

    int n;
    cin >> n;

    vector<pair<int, pair<int, int>>> a(n);
    for(int i = 0; i < n; i++){
        int c, s, score;
        cin >> c >> s >> score;
        a[i] = {score, {c, s}};
    }

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    map<int, int> m;

    int idx = 0;
    for(int i = 0; i < 3; i++){
        while(m[a[idx].second.first] >= 2){
            idx++;
        }
        cout << a[idx].second.first << " " << a[idx].second.second << "\n";
        m[a[idx].second.first]++;
        idx++;
    } 

}
