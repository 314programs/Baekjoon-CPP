#include <bits/stdc++.h>
using namespace std;

long long graph[101][101];
long long inf = 2147483647;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int node_cnt, connection_cnt;
    cin >> node_cnt >> connection_cnt; 

    for(int y = 1; y <= node_cnt; y++){
        for(int x = 1; x <= node_cnt; x++){
            graph[y][x] = inf;
        }
    }

    for(int i = 0; i < connection_cnt; i++){
        long long f, t, c;
        cin >> f >> t >> c;
        graph[f][t] = min(graph[f][t], c);
    }

    for(int i = 1; i <= node_cnt; i++){
        graph[i][i] = 0;
    }
    
    //3 nested loops
    for(int k = 1; k <= node_cnt; k++){
        for(int i = 1; i <= node_cnt; i++){
            for(int j = 1; j <= node_cnt; j++){
                //Is going through k faster?
                if(graph[i][j] > graph[i][k] + graph[k][j] && graph[i][k] != inf && graph[k][j] != inf){
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    for(int y = 1; y <= node_cnt; y++){
        for(int x = 1; x <= node_cnt; x++){
            if(graph[y][x] == inf) cout << "0 ";
            else cout << graph[y][x] << " ";
        }
        cout << "\n";
    }

}
