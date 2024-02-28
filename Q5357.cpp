//Trying more codeforces...

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--){
        string s;
        cin >> s;

        string ans = "";
        for(auto ch: s){
            if(ans.size() == 0 || ans.back() != ch){
                ans += ch;
            }
        }

        cout << ans << "\n";

    }
    
}
