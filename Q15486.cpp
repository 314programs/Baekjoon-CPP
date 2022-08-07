#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int list_len;
    cin >> list_len;

    vector<int> time(list_len);
    vector<int> wage(list_len);

    for(int i = 0; i < list_len; i++){
        cin >> time[i] >> wage[i];
    }

    int DP[list_len+1];
    memset(DP, 0, sizeof(DP));

    for(int i = 0; i < list_len; i++){
        if(time[i] + i > list_len){
            DP[i+1] = max(DP[i], DP[i+1]);
            continue;
        }

        DP[i + time[i]] = max(DP[i] + wage[i], DP[i + time[i]]);
        DP[i+1] = max(DP[i], DP[i+1]);
    }

    cout << DP[list_len];

}
