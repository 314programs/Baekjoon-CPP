#include <bits/stdc++.h>
using namespace std;

vector<int> dfs_order;
vector<int> graph[100000];
int visited[100000];

//Doing DFS using graph values given
void DFS(int start){
    if(visited[start] == 1){
        return;
    }
    dfs_order.push_back(start);
    visited[start] = 1;

    for(int ch: graph[start]){
        if(visited[ch] == 0){
            DFS(ch);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int nodes;

    cin >> nodes; 
    //Take input
    for(int i = 0; i < nodes-1; i++){
        int a,b;
        cin >> a >> b;
        a -= 1; b -= 1;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> order(nodes);
    vector<int> order_sort(nodes);

    for(int i = 0; i < nodes; i++){
        cin >> order[i];
        order[i] -= 1;
        //For sorting graph later
        order_sort[order[i]] = i;
    }

    for(int i = 0; i < nodes; i++){
        //Sort each node's child using the order_sort 
        sort(graph[i].begin(), graph[i].end(), [&](const int &u, const int &v){
            return order_sort[u] < order_sort[v];
        });
    }
    
    memset(visited, 0, sizeof(visited));
    
    DFS(0);
    //Check if calculated order is same with the order given
    if(dfs_order == order){
        cout << 1;
    }
    else{
        cout << 0;
    }

}

