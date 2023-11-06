#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    int s, e;
    cin >> s >> e;

    while(s <= e){
        cout << "All positions change in year " << s << "\n";
        s += 60;
    }

}
