//School...
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int tc;
    cin >> tc;
    while(tc--){
        string s;
        cin >> s;
        int s_len = s.length();

        if(s_len >= 6 && s_len <= 9){
            cout << "yes\n";
        }
        else{
            cout << "no\n";
        }

    }


}
