//2 days remain
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, w, h, l;
    cin >> n >> w >> h >> l;

    cout << min(n, (w/l)*(h/l));


}
