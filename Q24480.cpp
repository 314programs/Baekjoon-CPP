//So much free time in school...
//Why even go to school near the holidays when this is all we do?

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

vector<int> ans;
vector<int> connection[100001];
int visited[100001];
int cnt = 1;

void dfs(int start){
    ans[start] = cnt++;
    for(auto ch: connection[start]){
        if(visited[ch] == 0) continue;
        visited[ch] = 0;
        dfs(ch);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m, s;
    cin >> n >> m >> s;
    memset(visited, -1, sizeof(visited));
    
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        connection[a].push_back(b);
        connection[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        sort(connection[i].begin(), connection[i].end(), greater<int>());
    }
    visited[s] = 0;
    ans.assign(n+1, 0);
    dfs(s);

    for(int i = 1; i <= n; i++){
        cout << ans[i] << "\n";
    }
    

}
