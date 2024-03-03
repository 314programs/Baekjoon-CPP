#include <bits/stdc++.h>
using namespace std;

//Birthday's party for friend
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    string s;
    cin >> s;

    int n = s.length();
    for(int i = 1; i <= n; i++){
        cout << s[i-1];
        if(i%10 == 0) cout << "\n";
    }

}
