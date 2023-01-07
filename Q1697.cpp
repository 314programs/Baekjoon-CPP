#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int graph[100001];
    int current_pos, brother_pos;
    cin >> current_pos >> brother_pos;

    queue<int> q_;
    int visited[100001];
    memset(visited, -1, sizeof(visited));

    q_.push(current_pos);
    visited[current_pos] = 0;

    while(!q_.empty()){
        int temp = q_.front();
        q_.pop();

        if(temp + 1 <= 100000 && visited[temp + 1] == -1){
            q_.push(temp+1);
            visited[temp+1] = visited[temp] + 1;
        }
        if(temp - 1 >= 0 && visited[temp - 1] == -1){
            q_.push(temp-1);
            visited[temp-1] = visited[temp] + 1;
        }
        if(temp * 2 <= 100000 && visited[temp * 2] == -1){
            q_.push(temp*2);
            visited[temp*2] = visited[temp] + 1;
        }

        if(visited[brother_pos] != -1){
            cout << visited[brother_pos];
            break;
        }
    }
}

