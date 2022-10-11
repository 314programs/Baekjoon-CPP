#include <bits/stdc++.h>
using namespace std;

int graph[401][401];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    memset(graph, -1, sizeof(graph));

    int city_cnt, road_cnt;
    cin >> city_cnt >> road_cnt;

    for(int i = 0; i < road_cnt; i++){
        int f, t, c;
        cin >> f >> t >> c;
        graph[f][t] = c;
    }
    
    //Detecting cycles using floyd-warshall
    for(int k = 1; k <= city_cnt; k++){
        for(int i = 1; i <= city_cnt; i++){
            for(int j = 1; j <= city_cnt; j++){
                if((graph[i][j] == -1 || graph[i][j] > graph[i][k] + graph[k][j]) && graph[i][k] != -1 && graph[k][j] != -1){
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    int ans = -1;
    //Find smallest existing cycle
    for(int i = 1; i <= city_cnt; i++){
        if(ans == -1 || (graph[i][i] < ans && graph[i][i] != -1)) ans = graph[i][i];
    }
    cout << ans;

}
