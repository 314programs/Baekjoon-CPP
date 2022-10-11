#include <bits/stdc++.h>
using namespace std;



int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int emoji_num;
    cin >> emoji_num;

    queue<pair<int, int>> q;
    //BFS based on current emoji num and how many emoji is copied onto clipboard
    int visited[1001][1001];
    memset(visited, -1, sizeof(visited));

    q.push(make_pair(1, 0));
    visited[1][0] = 0;

    while(!q.empty()){
        int num_ = q.front().first;
        int clipboard_ = q.front().second;
        q.pop();

        if(num_ - 1 >= 0 && visited[num_ - 1][clipboard_] == -1){
            visited[num_ - 1][clipboard_] = visited[num_][clipboard_] + 1;
            q.push(make_pair(num_ - 1, clipboard_));
        }
        if(num_ + clipboard_ <= 1000 && visited[num_+clipboard_][clipboard_] == -1){
            visited[num_+clipboard_][clipboard_] = visited[num_][clipboard_] + 1;
            q.push(make_pair(num_+clipboard_, clipboard_));
        }
        if(visited[num_][num_] == -1){
            visited[num_][num_] = visited[num_][clipboard_] + 1;
            q.push(make_pair(num_, num_));
        }
    }

    int ans = 1001;
    for(int i = 0; i < 1001; i++){
        if(visited[emoji_num][i] != -1){
            ans = min(ans, visited[emoji_num][i]);
        }
    }
    cout << ans;

}

