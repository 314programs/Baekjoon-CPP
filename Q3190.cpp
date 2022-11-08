#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

struct coord{
    int x, y;
};

//This is very important as direction is arranged in a specific direction
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int time_p[10501];
int visited[200][200];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    int apple_num;
    cin >> apple_num;
    vector<coord> apples(apple_num);
    
    memset(visited, 0, sizeof(visited));
    memset(time_p, 0, sizeof(time_p));

    for(int i = 0; i < apple_num; i++){
        int x, y;
        cin >> y >> x;
        visited[y-1][x-1] = 2;
    }

    int turn_num;
    cin >> turn_num;

    for(int i = 0; i < turn_num; i++){
        int t;
        char dir;
        cin >> t >> dir;
        
        if(dir == 'D'){
            time_p[t] = 1;
        }
        else if(dir == 'L'){
            time_p[t] = -1;
        }
    }

    coord snake_pos = {0, 0};
    int cur_dir = 0;

    queue<coord> q;
    q.push(snake_pos);
    visited[0][0] = 1;
    
    //Time was confusing
    for(int t = 1; t < 15000; t++){
        snake_pos.x += dx[cur_dir];
        snake_pos.y += dy[cur_dir];
        //Bump into wall or ownself
        if(snake_pos.x < 0 || snake_pos.x >= n || snake_pos.y < 0 || snake_pos.y >= n || visited[snake_pos.y][snake_pos.x] == 1){
            cout << t;
            break;
        }
        
        //Delete the tail to keep the length constant unless snake ran into an apple
        if(visited[snake_pos.y][snake_pos.x] != 2){
            visited[q.front().y][q.front().x] = 0;
            q.pop();
        }
        visited[snake_pos.y][snake_pos.x] = 1;
        q.push(snake_pos);
        
        //Change direction
        cur_dir += time_p[t];
        cur_dir += 4;
        cur_dir %= 4;

        
    }


}
