#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    while(true){
        int tc;
        cin >> tc;
        if(tc == -1) break;

        int prev = 0;
        int ans = 0;
        while(tc--){
            int cs, ct;
            cin >> cs >> ct;
            ans += cs*(ct-prev);
            prev = ct;
        }
        cout << ans << " miles\n";
    }

}
