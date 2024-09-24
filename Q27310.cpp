#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    string s;
    cin >> s;

    int underbar = 0, colon = 0;
    for(auto ch: s){
        if(ch == ':'){
            colon++;
        }
        if(ch == '_'){
            underbar++;
        }
    }

    cout << s.size() + colon + (5*underbar);

}
