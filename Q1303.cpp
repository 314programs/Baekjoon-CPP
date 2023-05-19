#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long

void setIO(string s = ""){
	if(s == "") return;
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}

void bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int current = q.front();
        q.pop();
        cout << current << " ";

        for(auto ch: connection[current]){
            if(!visited[ch]){
                visited[ch] = true;
                q.push(ch);
            }
        }
    }
}

void dfs(int cur){
    cout << cur << " ";
    for(auto ch: connection[cur]){
        if(!visited[ch]){
            visited[ch] = true;
            dfs(ch);
        }
    }
}


int32_t main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);
 
	setIO();

    int n, m, s;
    cin >> n >> m >> s;
    memset(visited, false, sizeof(visited));

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        connection[a].push_back(b);
        connection[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        sort(connection[i].begin(), connection[i].end());
    }

    visited[s] = true;
    dfs(s);
    memset(visited, false, sizeof(visited));
    cout << "\n";

    bfs(s);

}
