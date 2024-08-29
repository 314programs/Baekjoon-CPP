//Can be a*(b/c) or a*(c/b)

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long

 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;

    cout << a*max(b,c)/min(b,c);

}
