#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<long long>> matrix;
long long mod = 1000003;

//We will calculate all possibilities using matrix multiplication
//a[i][j]^2 = sum of(a[i][k] * a[k][j])
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
    
    //* 5 because a[i][j] <= 5
    //They will be separated into a lot of bits (node num, time taken) represents paths to the node after time taken
    //Example: 1
    //(1,0) (1,1) (1,2) (1,3) (1,4)
    //(1,5) will not be needed as the node will be trasferred to (next node, 0)
    
    matrix ans(node_cnt*5, vector<long long>(node_cnt * 5, 0));
    //Marking diagonal for multiplication
    for(int i = 0; i < node_cnt*5; i++){
        ans[i][i] = 1;
    } 
    
    //Moving to the next minute
    matrix graph(node_cnt*5, vector<long long>(node_cnt * 5, 0));
    for(int i = 0; i < node_cnt; i++){
        for(int j = 0; j < 4; j++){
            graph[5*i+j][5*i+j+1] = 1;
        }
    }
    
    //Input
    for(int y = 0; y < node_cnt; y++){
        string s;
        cin >> s;
        for(int x = 0; x < node_cnt; x++){
            //0 means no path
            int temp = s[x] - '0';
            if(temp > 0){
                graph[5*y+temp-1][5*x] = 1;
            }
        }
    }
    
    //Multiply
    while(late_time > 0){
        if(late_time & 1){
            ans = ans * graph;
        }
        graph = graph * graph;
        late_time >>= 1;
    }
    
    //Since we started from 0 not 1, subtract 1
    start--; end--;
    //Times by 5 since we separated values into 5
    cout << ans[start*5][end*5];

}
