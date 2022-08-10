#include <bits/stdc++.h>
using namespace std;

int num_list[50001];
int sum_list[50001];
//Index of ppl, number of small train left
int DP[50001][4];

//Sum made easier
int s(int a, int b){
    return sum_list[b] - sum_list[a-1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> num_list[i];
        sum_list[i] = sum_list[i-1] + num_list[i];
    }

    int m;
    cin >> m;
    for(int j = 1; j <= 3; j++){
        for(int i = m*j; i <= n; i++){
            DP[i][j] = DP[i-1][j];
            //Skip or use the small train
            DP[i][j] = max(DP[i][j], DP[i-m][j-1] + s(i-m+1, i));
        }
    }
    cout << DP[n][3];

}
