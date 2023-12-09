//One day till math test
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string s;
    cin >> s;

    vector<int> a;
    string segment = "";

    for(auto ch: s){
        if(ch == '/'){
            a.push_back(stoi(segment));
            segment = "";
        }
        else{
            segment += ch;
        }
    }
    a.push_back(stoi(segment));

    if(a[0]+a[2] < a[1] || a[1] == 0){
        cout << "hasu";
    }
    else{
        cout << "gosu";
    }

}
