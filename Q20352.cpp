#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    double n;
    cin >> n;

    n /= M_PI;
    n = sqrt(n);
    cout << fixed << setprecision(7) << n*2*M_PI;

}
