#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<long long>> matrix;
matrix operator *(const matrix &a, const matrix &b){
    int n = a.size();
    matrix ans(n, vector<long long> (n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                ans[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int ppl_cnt, k, tc;
    cin >> ppl_cnt >> k >> tc;

    matrix graph(ppl_cnt, vector<long long> (ppl_cnt));
    for(int i = 0; i < ppl_cnt; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[i][a] = 1;
        graph[i][b] = 1;
    }

    matrix ans(ppl_cnt, vector<long long> (ppl_cnt));
    for(int i = 0; i < ppl_cnt; i++){
        ans[i][i] = 1;
    }
    
    //Calculate number of paths from one node to another
    int temp = k;
    while(temp > 0){
        if(temp & 1){
            ans = ans * graph;
        }
        graph = graph * graph;
        temp >>= 1;
    }
    
    while(tc--){
        int a, b;
        cin >> a >> b;
        a--; b--;
        
        //There is a path
        if(ans[a][b] != 0) cout << "death\n";
        else cout << "life\n";
    }

}
