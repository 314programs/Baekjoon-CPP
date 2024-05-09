//I must learn discrete mathematics...

#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);
    
    int n, h, v;
    cin >> n >> h >> v;

    cout << 4 * max(n-h, h) * max(n-v, v);

}
