#include <bits/stdc++.h>
using namespace std;
vector<int> graph[20001];
int visited[20001];

void BFS(int node_num, int color){
    visited[node_num] = color;
    for(auto ch: graph[node_num]){
        if(visited[ch] == 0){
            BFS(ch, 3-color);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int cases;
    cin >> cases;

    while(cases--){
        int nodes, connections;
        cin >> nodes >> connections;

        for(int i = 1; i <= nodes; i++){
            graph[i].clear();
            visited[i] = 0;
        }
        for(int i = 0; i < connections; i++){
            int a,b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for(int i = 1; i <= nodes; i++){
            if(visited[i] == 0){
                BFS(i, 1);
            }
        }
        
        //Checking if it is a Bipartite graph
        string answer = "YES";

        for(int i = 1; i <= nodes; i++){
            for(auto ch: graph[i]){
                if(visited[ch] == visited[i]){
                    answer = "NO";
                }
            }
        }

        cout << answer << "\n";
    }

    

}

