#include <bits/stdc++.h>
using namespace std;

bool check[50][50];
vector<string> graph(50);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int node_cnt;
    cin >> node_cnt;

    for(int y = 0; y < node_cnt; y++){
        cin >> graph[y];
    }
    
    //If there are 2 way roads, they can always be connected to not form a cycle
    //One way roads on the other hand cannot be changed, so if there is a one way road with a cycle, it cannot be changed
    for(int y = 0; y < node_cnt; y++){
        for(int x = 0; x < node_cnt; x++){
            if(graph[y][x] == 'Y' && graph[x][y] == 'N'){
                check[y][x] = true;
            }
        }
    }

    
    //Floyd-warshall to find cycle
    for(int k = 0; k < node_cnt; k++){
        for(int i = 0; i < node_cnt; i++){
            for(int j = 0; j < node_cnt; j++){
                if(check[i][k] == true && check[k][j] == true){
                    check[i][j] = true;
                }
            }
        }
    }

    string ans = "YES";
    //Started at node i and came back to node i, indicating a cycle
    for(int i = 0; i < node_cnt; i++){
        if(check[i][i] == true) ans = "NO";
    }
    cout << ans;



}
