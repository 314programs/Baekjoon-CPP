//Going on a school trip today so doing this early
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while(true){
        string s;
        getline(cin, s);
        if(s == "END"){
            break;
        }
        reverse(s.begin(), s.end());
        cout << s << "\n";
    }
}
