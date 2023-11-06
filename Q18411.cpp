//Math test
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    vector<int> a(3);
    for(int i = 0; i < 3; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    cout << a[1] + a[2];

}
