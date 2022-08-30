//Will explain later
#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<long long>> matrix;
long long mod = 1000003;

matrix operator * (const matrix &a, const matrix &b){
    int n = a.size();
    matrix ans(n, vector<long long>(n, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                ans[i][j] += a[i][k] * b[k][j];
            }
            ans[i][j] %= mod;
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int node_cnt, start, end, late_time;
    cin >> node_cnt >> start >> end >> late_time;

    matrix ans(node_cnt*5, vector<long long>(node_cnt * 5, 0));
    for(int i = 0; i < node_cnt*5; i++){
        ans[i][i] = 1;
    } 

    matrix graph(node_cnt*5, vector<long long>(node_cnt * 5, 0));
    for(int i = 0; i < node_cnt; i++){
        for(int j = 0; j < 4; j++){
            graph[5*i+j][5*i+j+1] = 1;
        }
    }

    for(int y = 0; y < node_cnt; y++){
        string s;
        cin >> s;
        for(int x = 0; x < node_cnt; x++){
            int temp = s[x] - '0';
            if(temp > 0){
                graph[5*y+temp-1][5*x] = 1;
            }
        }
    }

    while(late_time > 0){
        if(late_time & 1){
            ans = ans * graph;
        }
        graph = graph * graph;
        late_time >>= 1;
    }
    start--; end--;
    cout << ans[start*5][end*5];

}
