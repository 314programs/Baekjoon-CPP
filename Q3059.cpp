//Segtrees later
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    int tc;
    cin >> tc;
    while(tc--){
        int ans = 0;
        bool a[26];
        memset(a, false, sizeof(a));

        for(int i = 65; i <= 90; i++){
            ans += i;
        }
        string s;
        cin >> s;
        for(auto ch: s){
            if(!a[ch-'A']){
                ans -= ch;
                a[ch-'A'] = true;
            }
        }
        cout << ans << "\n";
    }
    

}
