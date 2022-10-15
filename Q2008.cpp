#include <bits/stdc++.h>
using namespace std;

int a[501];
//Using till ith horizontal line, start to j = cost
int DP[501][101];
const int inf = 1e9;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    //Vertical, horizontal
    cin >> n >> m;
    int from, to, erase, add;
    cin >> from >> to >> erase >> add;

    from--;
    to--;
    for(int i = 1; i <= m; i++){
        cin >> a[i];
        a[i]--;
    }

    //memset
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            DP[j][i] = inf;
        }
    }

    //Set up initial values...
    for(int i = 0; i < n; i++){
        if(i == from){
            DP[0][i] = 0;
        }
        else{
            DP[0][i] = abs(from - i) * add;
        }
    }

    //m number of lines used
    for(int i = 1; i <= m; i++){
        //j = start, k = end
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                //if j == k and if there are any horizontal lines being started from k or ended from k
                if(j == k && (a[i] == k || a[i]+1 == k)){
                    DP[i][k] = min(DP[i-1][j] + erase, DP[i][k]); 
                }
                //if there is a line between j and k
                //First case is between them when j > k, second case is when j < k
                else if((a[i] >= j && a[i]+1 <= k) || (a[i] >= k && a[i]+1 <= j)){
                    DP[i][k] = min(DP[i-1][j] + (abs(j-k)-1)*add, DP[i][k]);
                }
                //No line between j and k
                else{
                    DP[i][k] = min(DP[i-1][j] + abs(j-k)*add, DP[i][k]);
                }
            }
        }
    }

    cout << DP[m][to];

}
