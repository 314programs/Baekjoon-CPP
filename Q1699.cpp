//DP practice
//Did not know the fact I did not do this question

#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int num;
    cin >> num;

    int DP[100001];
    vector<int> sqs;
    DP[0] = 0;

    for(int i = 1; i <= num; i++){
        DP[i] = i;
        for(int j = 1; j*j <= i; j++){
            DP[i] = min(DP[i], DP[i-(j*j)]+1);
        }
    }

    cout << DP[num];

}
