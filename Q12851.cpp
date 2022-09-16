#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;
int visited[MAX+1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int sb, br;
    cin >> sb >> br;

    memset(visited, -1, sizeof(visited));
    visited[sb] = 0;
    queue<int> q;
    q.push(sb);

    int ans = -1;
    int method = 0;
    while(!q.empty()){
        int current = q.front();
        q.pop();
        
        int next_dist = visited[current] + 1;
        if(ans == -1 && current == br){
            ans = next_dist-1;
        }
        if(next_dist-1 == ans && current == br){
            method++;
        }

        if(current + 1 <= MAX && (visited[current+1] == -1 || visited[current+1] == next_dist)){
            visited[current+1] = next_dist;
            q.push(current+1);
        }
        if(current - 1 >= 0 && (visited[current-1] == -1 || visited[current-1] == next_dist)){
            visited[current-1] = next_dist;
            q.push(current-1);
        }
        if(current * 2 <= MAX && (visited[current*2] == -1 || visited[current*2] == next_dist)){
            visited[current*2] = next_dist;
            q.push(current*2);
        }
    }

    cout << ans << " " << method;

}
