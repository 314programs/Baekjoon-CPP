#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    int h, w;
    cin >> h >> w;

    int a[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            char n;
            cin >> n;
            if(n == 'B') a[i][j] = 'W';
            else a[i][j] = 'B';
        }
    }

    int cnt = 0;
    cin.ignore();
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            char n;
            cin >> n;
            if(n != a[i][j]) cnt++;
        }
    }
    cout << cnt;

}
