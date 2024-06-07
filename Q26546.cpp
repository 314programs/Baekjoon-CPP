#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long

 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--){
        string s;
        int start, end;
        cin >> s >> start >> end;   

        string ans = "";
        for(int i = 0; i < s.size(); i++){
            if(i < start || i >= end){
                ans += s[i];
            }
        }
        cout << ans << "\n";

    }

}
