#include <bits/stdc++.h>
using namespace std;

string s;
string a[3];

//length, idx of wanted letter(s), bridge number
int DP[101][21][3];

int solve(int len, int idx, int bridge){
    if(idx == s.length()) return 1;
    if(len >= a[1].length()) return 0;
    
    //Memoization
    int &ans = DP[len][idx][bridge];
    if(ans != -1) return ans;
    ans = 0;
    
    //Travel to next letter if next letter is the next letter for s
    //Length also increased, so no need for <=
    for(int i = len+1; i < a[1].length(); i++){
        if(s[idx] == a[3-bridge][i]){
            //Switch bridge
            ans += solve(i, idx+1, 3-bridge);
        }
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> s;
    string s1, s2;
    cin >> s1 >> s2;
    //I made them start from index 1 for convenience
    a[1] = "X" + s1;
    a[2] = "X" + s2;
    
    memset(DP, -1, sizeof(DP));
    cout << solve(0, 0, 1) + solve(0,0,2);
    
}
