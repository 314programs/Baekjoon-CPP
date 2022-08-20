#include <bits/stdc++.h>
using namespace std;

long long inf = 2147483646;
long long dist[501];

struct node{
    int from, to, cost;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--){
        int node_cnt, road_cnt, worm_cnt;
        cin >> node_cnt >> road_cnt >> worm_cnt;
        int total_cnt = road_cnt*2 + worm_cnt;
        
        //Should read question more carefully... did not write roads go both ways
        vector<node> connections(road_cnt*2 + worm_cnt);
        for(int i = 0; i < road_cnt*2; i += 2){
            int f, t, c;
            cin >> f >> t >> c;
            connections[i] = {f, t, c};
            connections[i+1] = {t, f, c};
        }

        for(int i = 0; i < worm_cnt; i++){
            int f, t, c;
            cin >> f >> t >> c;
            connections[i + road_cnt*2] = {f, t, -c};
        }
        
        //Set every node to 0 since can start from everywhere
        memset(dist, 0, sizeof(dist));
        bool loop_ = false;
        
        //Bellman-ford
        for(int i = 1; i <= node_cnt; i++){
            for(int j = 0; j < total_cnt; j++){
                int f = connections[j].from;
                int t = connections[j].to;
                int c = connections[j].cost;
                if(dist[f] + c < dist[t]){
                    dist[t] = dist[f] + c;
                    if(i == node_cnt){
                        loop_ = true;
                    }
                }
            }
        }

        if(loop_){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    

}
