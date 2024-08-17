#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int total;
    cin >> total;

    for(int i = 0; i < 9; i++){
        int num;
        cin >> num;
        total -= num;
    }

    cout << total;

}
