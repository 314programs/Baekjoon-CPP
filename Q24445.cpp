//Need rest...

#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int n, m, s;
    cin >> n >> m >> s;
    vector<int> edge[n+1];

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        sort(edge[i].begin(), edge[i].end(), greater<int>());
    }

    int cnt = 1;
    vector<int> ans(n+1, 0);
    queue<int> q;
    q.push(s);

    vector<int> visited(n+1, -1);
    visited[s] = 0;

    while(!q.empty()){
        int current = q.front();
        q.pop();
        ans[current] = cnt++;

        for(auto ch: edge[current]){
            if(visited[ch] == -1){
                visited[ch] = 0;
                q.push(ch);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        cout << ans[i] << "\n";
    }



}
