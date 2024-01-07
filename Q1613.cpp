#include <bits/stdc++.h>
using namespace std;

bool dist[401][401];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int node_cnt, connection_cnt;
    cin >> node_cnt >> connection_cnt;

    memset(dist, false, sizeof(dist));
    for(int i = 0; i < connection_cnt; i++){
        int f, t;
        cin >> f >> t;
        dist[f][t] = true;
    }
    
    //Floyd-warshall
    for(int k = 1; k <= node_cnt; k++){
        for(int i = 1; i <= node_cnt; i++){
            for(int j = 1; j <= node_cnt; j++){
                if(dist[i][k] && dist[k][j]) dist[i][j] = true;
            }
        }
    }

    int tc;
    cin >> tc;
    while(tc--){
        int f, t;
        cin >> f >> t;
        //Happened early
        if(dist[f][t]){
            cout << -1 << "\n";
        }
        //Happened later
        else if(dist[t][f]){
            cout << 1 << "\n";
        }
        //IDK
        else{
            cout << 0 << "\n";
        }

    }
}
