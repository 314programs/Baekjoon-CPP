#include "cyberland.h"
#include <vector>
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 1e17 + 7;
const int li = 100005;

int n, m, k, h;
int arr[li], t, vis[li][100], connected[li];
double pw[100];
vector<pair<int, int>> edge[li];
vector<int> vec;

void dfs(int node){
    if(connected[node]) return;
    connected[node] = 1;
    if(node == h) return;

    for(auto &ch: edge[node]){
        if(connected[ch.first] == 0){
            dfs(ch.first);
        }
    }
}

double sp(){
    priority_queue<pair<double, pair<int, int>>> pq;
    for(auto ch: vec){
        for(int i = 0; i <= k; i++){
            pq.push({0, {i, ch}});
        }
    }

    while(!pq.empty()){
        double tim = -pq.top().first;
        int div = pq.top().second.first;
        int node = pq.top().second.second;
        pq.pop();

        if(div < 0) continue;
        if(vis[node][div]) continue;
        vis[node][div] = 1;
        if(node == h && div == 0){
            return tim;
        }
        if(node == h) continue;

        for(auto &ch: edge[node]){
            int yes = div;
            if(vis[ch.first][yes] == 0){
                pq.push({-tim-ch.second/pw[div], {yes, ch.first}});
            }
            if(arr[ch.first] == 2){
                yes--;
                if(yes >= 0 && vis[ch.first][yes] == 0){
                    pq.push({-tim-ch.second/pw[div], {yes, ch.first}});
                }
            }
        }
    }

    return -1;

}

double solve(int32_t N, int32_t M, int32_t K, int32_t H, vector<int32_t> x, vector<int32_t> y, vector<int32_t> c, vector<int32_t> _arr) {
    K = min(K, 95);
    n = N; m = M; k = K; h = H;
    
    pw[0] = 1;
    for(int i = 1; i <= 95; i++){
        pw[i] = pw[i-1] + pw[i-1];
    }

    vec.clear();
    vec.push_back(0);

    for(int i = 0; i < n; i++){
        edge[i].clear();
        connected[i] = 0;
        for(int j = 0; j <= k; j++){
            vis[i][j] = 0;
        }
        arr[i] = _arr[i];
    }

    for(int i = 0; i < m; i++){
        edge[x[i]].push_back({y[i], c[i]});
        edge[y[i]].push_back({x[i], c[i]});
    }
    dfs(0);

    for(int i = 0; i < n; i++){
        if(arr[i] == 0 && connected[i]){
            vec.push_back(i);
        }
    }
    if(connected[h] == 0) return -1;
    return sp();
    
}

/*
int32_t main() {
    int T;
    assert(1 == scanf("%lld", &T));
    while (T--){
        int N,M,K,H;
        assert(4 == scanf("%lld %lld %lld\n%lld", &N, &M, &K, &H));
        vector<int> x(M);
        vector<int> y(M);
        vector<int> c(M);
        vector<int> arr(N);
        for (int i=0;i<N;i++)
        assert(1 == scanf("%lld", &arr[i]));
        for (int i=0;i<M;i++)
        assert(3 == scanf("%lld %lld %lld", &x[i], &y[i], &c[i]));
        printf("%.12lf\n", solve(N, M, K, H, x, y, c, arr));
    }
}
*/
