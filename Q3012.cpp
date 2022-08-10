#include <bits/stdc++.h>
using namespace std;

const long long mod = 100000;
string s;
long long DP[200][200];
//Prepare brackets
char open[4] = "([{";
char close[4] = ")]}";

long long go(int i, int j){
    //Over the limit
    if(i > j){
        return 1;
    }
  
    //Memoization
    long long &ans = DP[i][j];
    if(ans != -1) return ans;
    ans = 0;
    
    //Divide into 2
    for(int x = i+1; x <= j; x += 2){
        //What type of bracket can be used for start and end of the divide
        for(int y = 0; y < 3; y++){
            if(s[i] == open[y] || s[i] == '?'){
                if(s[x] == close[y] || s[x] == '?'){
                    //Add possibilities to the sum
                    long long temp = go(i+1, x-1) * go(x+1, j);
                    //5 digit criteria
                    ans += temp;
                    if(ans >= mod){
                        ans = mod + ans % mod;
                    }
                }
            }
        }
    }
    return ans;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    memset(DP, -1, sizeof(DP));

    int s_len;
    cin >> s_len;
    cin >> s;

    long long ans = go(0, s_len-1);
    //5 digit criteria
    if(ans >= mod){
        printf("%05lld\n", ans%mod);
    }
    else{
        cout << ans;
    }

}
