#include <bits/stdc++.h>
using namespace std;

struct node{
    int to, cost;
};

vector<node> connection_1[10001];
vector<node> connection_2[10001];
int in_degrees_1[10001];
int in_degrees_2[10001];

int dist[10001];
bool check[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    memset(check, false, sizeof(check));
    int city_cnt, road_cnt;
    cin >> city_cnt >> road_cnt;

    memset(in_degrees_1, 0, sizeof(in_degrees_1));
    memset(in_degrees_2, 0, sizeof(in_degrees_2));

    for(int i = 0; i < road_cnt; i++){
        int f, t, c;
        cin >> f >> t >> c;
        connection_1[f].push_back({t, c});
        connection_2[t].push_back({f, c});
        in_degrees_1[t] += 1;
        in_degrees_2[f] += 1;
    }

    int start, end;
    cin >> start >> end;

    queue<int> q;

    for(int i = 1; i <= city_cnt; i++){
        if(in_degrees_1[i] == 0){
            q.push(i);
        }
    }
    
    //Topological search
    while(!q.empty()){
        int current = q.front();
        q.pop();

        for(auto ch: connection_1[current]){
            in_degrees_1[ch.to] -= 1;
            dist[ch.to] = max(dist[ch.to], dist[current] + ch.cost);

            if(in_degrees_1[ch.to] == 0){
                q.push(ch.to);
            }
        }
    }

    cout << dist[end] << "\n";
    for(int i = 1; i <= city_cnt; i++){
        in_degrees_1[i] = in_degrees_2[i];
    }
    int ans = 0;
    check[end] = true;

    for(int i = 1; i <= city_cnt; i++){
        if(in_degrees_1[i] == 0){
            q.push(i);
        }
    }
    
    //Do topological search twice to backtrack
    while(!q.empty()){
        int current = q.front();
        q.pop();

        for(auto ch: connection_2[current]){
            //If the calculated distance matches the actual distance
            if(check[current] && dist[current] - dist[ch.to] == ch.cost){
                ans += 1;
                check[ch.to] = true;
            }

            in_degrees_1[ch.to] -= 1;
            if(in_degrees_1[ch.to] == 0){
                q.push(ch.to);
            }
        }
    }

    cout << ans;

}
