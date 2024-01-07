#include <bits/stdc++.h>
using namespace std;

long long graph[101][101];
long long next_node[101][101];
long long inf = 2147483647;

//Backtracking to find route
void print_ans(long long from, long long to){
    if(next_node[from][to] == -1){
        cout << "0\n";
        return;
    }

    queue<int> q;
    q.push(from);

    while(from != to){
        from = next_node[from][to];
        q.push(from);
    }

    cout << q.size() << " ";
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    memset(next_node, -1, sizeof(next_node));
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
        next_node[f][t] = t;
    }

    for(int i = 1; i <= node_cnt; i++){
        graph[i][i] = 0;
    }
    
    //Floyd
    for(int k = 1; k <= node_cnt; k++){
        for(int i = 1; i <= node_cnt; i++){
            for(int j = 1; j <= node_cnt; j++){
                if(graph[i][j] > graph[i][k] + graph[k][j] && graph[i][k] != inf && graph[k][j] != inf){
                    graph[i][j] = graph[i][k] + graph[k][j];
                    next_node[i][j] = next_node[i][k];
                }
            }
        }
    }
    
    //Print graph
    for(int y = 1; y <= node_cnt; y++){
        for(int x = 1; x <= node_cnt; x++){
            if(graph[y][x] == inf) cout << "0 ";
            else cout << graph[y][x] << " ";
        }
        cout << "\n";
    }
    
    //Print route
    for(int f = 1; f <= node_cnt; f++){
        for(int t = 1; t <= node_cnt; t++){
            if(graph[f][t] == inf){
                cout << "0\n";
            }
            else{
                print_ans(f, t);
            }
        }
    }

}
