//Condition was bad, so bronze today
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    while(true){
        string s;
        cin >> s;
        if(s == "0") break;

        int ans = 0;
        for(auto ch: s){
            if(ch - '0' == 1){
                ans += 2;
            }
            else if(ch - '0' == 0){
                ans += 4;
            }
            else{
                ans += 3;
            }
        }
        ans += s.length()-1 + 2;
        cout << ans << '\n';
    }
    
}
