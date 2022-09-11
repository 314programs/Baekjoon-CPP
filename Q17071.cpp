#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int s, b;
    cin >> s >> b;
    int MAX = 500000;

    int dist = -1;
    //Divide visited into even and odd
    //Point x can be arrived at t, t+2, t+4... so divide into even and odd
    int visited[MAX+1][2];
    int brother[MAX+1];

    memset(visited, -1, sizeof(visited));
    memset(brother, -1, sizeof(brother));

    queue<pair<int, int>> q;
    q.push(make_pair(s, 0));
    visited[s][0] = 0;

    int add = 1;
    brother[b] = 0;
    while(true){
        b += add;
        if(b > MAX) break;
        brother[b] = add;
        add += 1;
    }
    
    //BFS using time
    while(!q.empty()){
        auto current = q.front();
        q.pop(); 

        int x = current.first;
        int time = current.second+1;

        if(x + 1 <= MAX && visited[x+1][time%2] == -1){
            visited[x+1][time%2] = time;
            q.push(make_pair(x+1, time));
        }
        if(x - 1 >= 0 && visited[x-1][time%2] == -1){
            visited[x-1][time%2] = time;
            q.push(make_pair(x-1, time));
        }
        if(x * 2 <= MAX && visited[x*2][time%2] == -1){
            visited[x*2][time%2] = time;
            q.push(make_pair(x*2, time));
        }
    }

    for(int j = 0; j < 2; j++){
        for(int i = 0; i <= MAX; i++){
            if((brother[i] - visited[i][j])%2 == 0 && brother[i] >= visited[i][j]){
                if(dist == -1 || dist > brother[i]){
                    dist = brother[i];
                }
            }
        }
    }

    cout << dist;


}
