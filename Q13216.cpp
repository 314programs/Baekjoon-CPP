#include <bits/stdc++.h>
using namespace std;

//THIS WAS IN MCO 2015
//HOW

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string s;
    cin >> s;

    int a_total = 0;
    int b_total = 0;

    int a = 0;
    int b = 0;
    for(auto ch: s){
        if(ch == 'A'){
            a++;
        }
        if(ch == 'B'){
            b++;
        }
        if(a == 21){
            a_total++;
            cout << a << "-" << b << "\n";
            a = 0; b = 0;
        }
        if(b == 21){
            b_total++;
            cout << a << "-" << b << "\n";
            a = 0; b = 0;
        }
    }

    if(a_total == 2){
        cout << "A";
    }
    if(b_total == 2){
        cout << "B";
    }

}
