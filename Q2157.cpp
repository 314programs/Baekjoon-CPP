#include <bits/stdc++.h>
using namespace std;

int graph[301][301];

//from ith city, went though j number of cities = maximum score for food
int DP[301][301];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    memset(graph, 0, sizeof(graph));
    memset(DP, -1, sizeof(DP));

    while(k--){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = max(graph[a][b], c);
    }

    DP[1][1] = 0;
    //j = number of city travelled, i = from what city
    for(int j = 1; j < m; j++){
        for(int i = 1; i <= n; i++){
            //Path not there
            if(DP[i][j] == -1) continue;
            
            //k = to what city
            for(int k = i+1; k <= n; k++){
                if(graph[i][k] > 0){
                    //Add current value
                    DP[k][j+1] = max(DP[k][j+1], graph[i][k] + DP[i][j]);
                }
            }
        }
    }

    int ans = 0;
    for(int i = 2; i <= n; i++){
        ans = max(ans, DP[n][i]);
    }
    cout << ans;

}
