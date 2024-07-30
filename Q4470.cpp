//incase...
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int s_cnt;
    cin >> s_cnt;
    cin.ignore();
    
    for(int i = 1; i <= s_cnt; i++){
        string s;
        getline(cin, s);
        cout << i << ". " << s << "\n";
    }

}
