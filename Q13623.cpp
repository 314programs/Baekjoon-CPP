//physics test
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;

    if(a == b && c != a){
        cout << "C";
    }
    else if(b == c && a != b){
        cout << "A";
    }
    else if(a == c && b != c){
        cout << "B";
    }
    else{
        cout << "*";
    }

}
