//too much maths hw
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long

bool vowel(char s){
    if(s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u'){
        return true;
    }
    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    string s;
    cin >> s;

    int cnt = 0;
    for(auto ch: s){
        if(vowel(ch)) cnt++;
    }
    cout << cnt;


}
