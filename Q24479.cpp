//Simple DFS...
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

vector<int> connection[100001];
int ans[100001] = {0};
int visited[100001] = {0};
int cnt = 1;

void bfs(int start){
    ans[start] = cnt++;
    for(auto ch : connection[start]){
        if(visited[ch] == 0){
            visited[ch] = 1;
            bfs(ch);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m, s;
    cin >> n >> m >> s;
    
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        connection[a].push_back(b);
        connection[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        sort(connection[i].begin(), connection[i].end());
    }

    visited[s] = 1;
    bfs(s);
    for(int i = 1; i <= n; i++){
        cout << ans[i] << "\n";
    }

}
