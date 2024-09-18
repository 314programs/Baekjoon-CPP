#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);
 
    float n;
    cin >> n;
    n = sqrt(n);

    cout << fixed << setprecision(8) << n*4;
 
}
