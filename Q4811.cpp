//Solution using catalan numbers
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    while(true){
        int num;
        cin >> num;

        if(num == 0) break;
        int n = num*2, m = num;

        long long DP[61][61];
        DP[1][1] = 1;
        for(int y = 2; y <= n; y++){
            for(int x = 1; x <= y; x++){
                DP[y][x] = DP[y-1][x] + DP[y-1][x-1];
            }
        }
        cout << DP[n][m] - DP[n][m-1] << "\n";

    }
}

//Solution using DP...
//Had hard time remembering how to do DP recursion
#include <bits/stdc++.h>
using namespace std;

long long DP[61][61];

long long solve(int whole, int half){
    DP[whole][half] = 0;
    if(whole > 0){
        //Memoization
        if(DP[whole-1][half+1] != -1) DP[whole][half] += DP[whole-1][half+1];
        else DP[whole][half] += solve(whole-1, half+1);
    }

    if(half > 0){
        if(DP[whole][half-1] != -1) DP[whole][half] += DP[whole][half-1];
        else DP[whole][half] += solve(whole, half-1);
    }
    return DP[whole][half];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    while(true){
        int num;
        cin >> num;

        if(num == 0) break;
        memset(DP, -1, sizeof(DP));

        DP[0][0] = 0;
        DP[0][1] = 1;

        cout << solve(num, 0) << "\n";
    }
}
