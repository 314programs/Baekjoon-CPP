#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    int a, q;
    cin >> a >> q;
    q += 60;

    cout << min(a, q) * 1500 + (max(a-q, (int)0))*3000;

}
