#include <bits/stdc++.h>
using namespace std;

int Dy[4] = {1,-1,0,0};
int Dx[4] = {0,0,1,-1};

int dimension;
int graph[25][25];
int visited[25][25];

int BFS(int x_, int y_){
    int total_ = 0;
    queue<pair<int, int>> q_;
    q_.push(make_pair(y_, x_));
    visited[y_][x_] = 1;

    while(!q_.empty()){
        total_ += 1;
        int y = q_.front().first;
        int x = q_.front().second;
        q_.pop();

        for(int i = 0; i < 4; i++){
            int new_y = y + Dy[i];
            int new_x = x + Dx[i];
            if(new_y >= 0 && new_y < dimension && new_x >= 0 && new_x < dimension && visited[new_y][new_x] != 1 && graph[new_y][new_x] == 1){
                visited[new_y][new_x] = 1;
                q_.push(make_pair(new_y, new_x));
            }
        }
    }
    return total_;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> dimension;
    cin.ignore();
    vector<int> sizes_;

    for(int i = 0; i < dimension; i++){
        string temp;
        getline(cin, temp);
        for(int j = 0; j < dimension; j++){
            graph[i][j] = temp[j]-'0';
        }
    }

    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            if(visited[i][j] != 1 && graph[i][j] == 1){
                sizes_.push_back(BFS(j, i));
            }
        }
    }

    sort(sizes_.begin(), sizes_.end());
    cout << sizes_.size() << "\n";
    for(auto ch: sizes_){
        cout << ch << "\n";
    }

}

