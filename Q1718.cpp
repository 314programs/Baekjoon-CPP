#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
#define int long long

void setIO(string s = ""){
	if(s == "") return;
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}

int32_t main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string s;
    string code;
    getline(cin, s);
    cin >> code;

    int n = code.length();
    int n2 = s.length();
    for(int i = 0; i < n2; i++){
        if(s[i] == ' ') cout << " ";
        else{
            int push = code[i%n] - 97 + 1;
            int cur = s[i] - 97;
            cur = (cur - push + 26)%26;
            cout << (char)(cur + 97); 
        }
    }

}
