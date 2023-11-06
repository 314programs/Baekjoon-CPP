//codeforces
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);
 
    string cur;
    cin >> cur;

    int n;
    cin >> n;
    int cnt = 0;
    while(n--){
        string s;
        cin >> s;
        if(s == cur){
            cnt++;
        }
    }
    cout << cnt;

}
