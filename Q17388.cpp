//Physics test?!?!?
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int s, g, h;
    cin >> s >> g >> h;

    if(s+g+h >= 100){
        cout << "OK";
    }
    else{
        if(s < g && s < h){
            cout << "Soongsil";
        }
        if(g < s && g < h){
            cout << "Korea";
        }
        if(h < s && h < g){
            cout << "Hanyang";
        }
    }

}
