#include <bits/stdc++.h>
using namespace std;
vector<int> graph[2000];
bool found = false;
int visited[2001];

void BFS(int node_num, int depth){
    //Exit if located
    if(depth == 4){
        found = true;
        return;
    }

    if(found == true){
        return;
    }
    
    //DFS, toggle the visited to allow next starting point to visit said location
    visited[node_num] = 1;
    for(auto ch: graph[node_num]){
        if(visited[ch] == 1) continue;
        BFS(ch, depth+1);
    }
    visited[node_num] = 0;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int nodes, connections;
    cin >> nodes >> connections;
    
    //Make graph
    for(int i = 0; i < connections; i++){
        int a,b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    //Check, starting from each node
    for(int i = 0; i < nodes; i++){
        BFS(i, 0);
        if(found){
            cout << 1;
            return 0;
        }
    }

    cout << 0;
}

