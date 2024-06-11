#include <bits/stdc++.h>
using namespace std;

int main(void){
    long A,B,C;
    cin >> A >> B >> C;

    cout << (A+B)%C << "\n";
    cout << ((A%C) + (B%C))%C << "\n";
    cout << (A*B)%C << "\n";
    cout << ((A%C) * (B%C))%C << "\n";

}
