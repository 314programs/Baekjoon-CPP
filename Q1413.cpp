//I have no idea what this is... so I will edit the explanation later
#include <bits/stdc++.h>
using namespace std;

long long DP[21][21];

long long gcd(long long a, long long b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    memset(DP, 0, sizeof(DP));
    int box_cnt, bomb_cnt;
    cin >> box_cnt >> bomb_cnt;

    DP[1][1] = 1;
    for(int i = 2; i <= box_cnt; i++){
        for(int j = 1; j <= i; j++){
            DP[i][j] = DP[i-1][j-1] + (i-1) * DP[i-1][j];
        }
    }

    long long can = 0;
    for(int i = 1; i <= bomb_cnt; i++){
        can += DP[box_cnt][i];
    }

    long long cant = 1;
    for(int i = 1; i <= box_cnt; i++){
        cant *= i;
    }
    
    long long g = gcd(can, cant);
    can /= g;
    cant /= g;
    cout << can << "/" << cant;

}
