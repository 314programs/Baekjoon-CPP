#include <bits/stdc++.h>
using namespace std;

int move_[101];
int visited[101];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int ladder, snake;
    cin >> ladder >> snake;

    for(int i = 1; i <= 100; i++){
        move_[i] = i;
    }

    for(int i = 0; i < ladder + snake; i++){
        int from, to;
        cin >> from >> to;
        move_[from] = to;
    }

    memset(visited, -1, sizeof(visited));
    visited[1] = 0;

    queue<int> q_;
    q_.push(1);

    while(!q_.empty()){
        int temp = q_.front();
        q_.pop();

        for(int i = 1; i <= 6; i++){
            if(temp+i <= 100 && (visited[move_[temp+i]] == -1 || visited[temp] + 1 < visited[move_[temp+i]])){
                visited[move_[temp+i]] = visited[temp] + 1;
                q_.push(move_[temp+i]);
            }
        }
    }

    cout << visited[100];
}


 
