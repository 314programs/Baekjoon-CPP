#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int list_len;
    cin >> list_len;

    vector<int> graph(list_len);
    for(int i = 0; i < list_len; i++){
        cin >> graph[i];
    }

    int DP[list_len];
    memset(DP, -1, sizeof(DP));
    DP[0] = 0;

    for(int i = 0; i < list_len; i++){
        //Cannot move onto this space
        if(DP[i] == -1) continue;
        //Mark all spaces that can be jumped from current space (i)
        for(int j = 1; j <= graph[i]; j++){
            if(i + j >= list_len){
                break;
            } 
            //The space that can be jumped to is not marked or has bigger jump number then the current
            if(DP[i+j] == -1 || DP[i+j] > DP[i] + 1){
                DP[i + j] = DP[i] + 1;
            }
        }
    }

    cout << DP[list_len - 1];

}
