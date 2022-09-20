#include <bits/stdc++.h>
using namespace std;

int d[10][10][10][10];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int height, width;

struct node{
    int x, y;
};

//Movement, hole
pair<bool, bool> movement(int & current_x, int & current_y, int dir, vector<string> & graph){
    if(graph[current_y][current_x] == '.') return make_pair(false, false);
    bool move = false;
    //Move in 1 direction until...
    while(true){
        int nx = current_x + dx[dir];
        int ny = current_y + dy[dir];
        //Out of bounds
        if(nx < 0 || nx >= width || ny < 0 || ny >= height){
            return make_pair(move, false);
        }
        //In hole
        if(graph[ny][nx] == 'O'){
            graph[current_y][current_x] = '.';
            move = true;
            return make_pair(move, true);
        }
        //Blocked
        if(graph[ny][nx] != '.'){
            return make_pair(move, false);
        }
        //keep moving
        if(graph[ny][nx] == '.'){
            move = true;
            swap(graph[current_y][current_x], graph[ny][nx]);
            current_x = nx;
            current_y = ny;
        }
    }

    return make_pair(false, false);
}

pair<bool, bool> next(int & bx, int & by, int & rx, int & ry, int dir, vector<string> graph){
    graph[by][bx] = 'B';
    graph[ry][rx] = 'R';
    bool blue_hole = false, red_hole = false;
    
    //Checks on conditions of red or blue balls going in the hole
    while(true){
        pair<bool, bool> blue_p = movement(bx, by, dir, graph);
        pair<bool, bool> red_p = movement(rx, ry, dir, graph);
        if(blue_p.first == false && red_p.first == false){
            break;
        }
        if(blue_p.second) blue_hole = true;
        if(red_p.second) red_hole = true;
    } 

    return make_pair(blue_hole, red_hole);

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    cin >> height >> width;
    vector<string> graph(height);

    node hole;
    node blue;
    node red;
    
    //Saving coordinates
    for(int y = 0; y < height; y++){
        cin >> graph[y];
        for(int x = 0; x < width; x++){
            if(graph[y][x] == 'B'){
                blue = {x, y};
                graph[y][x] = '.';
            }
            if(graph[y][x] == 'R'){
                red = {x, y};
                graph[y][x] = '.';
            }
            if(graph[y][x] == 'O'){
                hole = {x, y};
            }
        }
    }
    
    //Implementation of BFS
    memset(d, -1, sizeof(d));
    d[blue.x][blue.y][red.x][red.y] = 0;
    queue<pair<node, node>> q;
    q.push(make_pair((node){blue.x, blue.y}, (node){red.x, red.y}));

    bool found = false;
    int ans = -1;
    while(!q.empty()){
        node current_b = q.front().first;
        node current_r = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            bool hole_blue, hole_red;
            node next_b = current_b, next_r = current_r;
            tie(hole_blue, hole_red) = next(next_b.x, next_b.y, next_r.x, next_r.y, i, graph);
            //Blue ball cannot go in the hole
            if(hole_blue){
                continue;
            }
            if(hole_red){
                found = true;
                ans = d[current_b.x][current_b.y][current_r.x][current_r.y] + 1;
                break;
            }

            if(d[next_b.x][next_b.y][next_r.x][next_r.y] != -1) continue;
            d[next_b.x][next_b.y][next_r.x][next_r.y] = d[current_b.x][current_b.y][current_r.x][current_r.y] + 1;
            q.push(make_pair(next_b, next_r));
        }
        if(found){
            break;
        }
    }

    cout << ans;

}
