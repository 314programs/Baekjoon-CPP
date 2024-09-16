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
    cin >> s;
    if(s == "fdsajkl;" || s == "jkl;fdsa"){
        cout << "in-out";
    }
    else if(s == "asdf;lkj" || s == ";lkjasdf"){
        cout << "out-in";
    }
    else if(s == "asdfjkl;"){
        cout << "stairs";
    }
    else if(s == ";lkjfdsa"){
        cout << "reverse";
    }
    else{
        cout << "molu";
    }
}
