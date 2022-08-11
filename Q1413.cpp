#include <bits/stdc++.h>
using namespace std;

//Length of sequence, number of cycles
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
    //Stirling numbers of first kind
    for(int i = 2; i <= box_cnt; i++){
        for(int j = 1; j <= i; j++){
            //DP[i-1][j-1] = Previous case where the ith number makes cycle alone

            //Cases when ith number goes into cycles that exists
            //DP[i-1][j] = Number of cycles previously
            //(i-1) = Number of cycles that we can put our number into
            DP[i][j] = DP[i-1][j-1] + (i-1) * DP[i-1][j];
        }
    }
    
    //Sequence with length of box_cnt, with all possible number of cycles are added to can
    long long can = 0;
    for(int i = 1; i <= bomb_cnt; i++){
        can += DP[box_cnt][i];
    }
    
    //All possibilities
    long long cant = 1;
    for(int i = 1; i <= box_cnt; i++){
        cant *= i;
    }
    
    //Finding highest common factor to turn it into a fraction
    long long g = gcd(can, cant);
    can /= g;
    cant /= g;
    cout << can << "/" << cant;

}
