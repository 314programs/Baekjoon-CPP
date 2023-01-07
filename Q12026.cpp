#include <bits/stdc++.h>
using namespace std;

//What character must come before?
char get_prev(char c){
    if(c == 'B') return 'J';
    if(c == 'O') return 'B';
    if(c == 'J') return 'O';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int num;
    cin >> num;

    string s;
    cin >> s;

    vector<int> DP(num, -1);
    DP[0] = 0;
    
    //i = current char, j = previous char
    for(int i = 1; i < num; i++){
        //Current and (should be) previous char
        char now = s[i];
        char prev = get_prev(now);
        for(int j = 0; j < i; j++){
            //If can go from j to i
            if(DP[j] == -1) continue;
            if(s[j] != prev) continue;
            //Find min
            int cost = DP[j] + (i-j) * (i-j);
            if(DP[i] == -1 || DP[i] > cost){
                DP[i] = cost;
            }
        }
    }
    cout << DP[num-1];

}
