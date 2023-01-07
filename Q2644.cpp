//Must finish... graph theory part today...

#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> connection[n+1];
    int visited[n+1];
    memset(visited, -1, sizeof(visited));

    int a, b;
    cin >> a >> b;

    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int c, d;
        cin >> c >> d;
        connection[c].push_back(d);
        connection[d].push_back(c);
    }

    queue<int> q;
    q.push(a);
    visited[a] = 0;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(auto ch: connection[cur]){
            if(visited[ch] == -1){
                visited[ch] = visited[cur]+1;
                q.push(ch);
            }
        }
    }

    cout << visited[b];
    

}
