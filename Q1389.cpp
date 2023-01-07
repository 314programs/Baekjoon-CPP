#include <bits/stdc++.h>
using namespace std;

long long graph[101][101];
long long next_node[101][101];
long long inf = 2147483647;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int node_cnt, friend_cnt;
    cin >> node_cnt >> friend_cnt;

    for(int y = 1; y <= node_cnt; y++){
        for(int x = 1; x <= node_cnt; x++){
            if(y == x) graph[y][x] = 0;
            else graph[y][x] = inf;
        }
    }

    for(int i = 0; i < friend_cnt; i++){
        int f, t;
        cin >> f >> t;
        graph[f][t] = 1;
        graph[t][f] = 1;
    }
    
    //Floyd
    for(int k = 1; k <= node_cnt; k++){
        for(int i = 1; i <= node_cnt; i++){
            for(int j = 1; j <= node_cnt; j++){
                if(graph[i][j] > graph[i][k] + graph[k][j]){
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    long long min_val = inf;
    long long min_person = -1;

    for(int y = 1; y <= node_cnt; y++){
        long long temp = 0; 
        for(int x = 1; x <= node_cnt; x++){
            temp += graph[y][x];
        }
        if(temp < min_val){
            min_val = temp;
            min_person = y;
        }
    }

    cout << min_person;

}
