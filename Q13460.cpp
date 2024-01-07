//Bitmasking practice...
#include <bits/stdc++.h>
using namespace std;

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
const int limit = 10;
int height, width;

//Generate set of directions
vector<int> generate(int k){
    vector<int> a(limit);
    for(int i = 0; i < limit; i++){
        a[i] = (k&3);
        k >>= 2;
    }
    return a;
}

pair<bool, bool> move(int & start_x, int & start_y, int dir, vector<string> & graph){
    if(graph[start_y][start_x] == '.') return make_pair(false, false);
    bool moved = false;
    while(true){
        int nx = dx[dir] + start_x;
        int ny = dy[dir] + start_y;

        //Outside bounds
        if(nx < 0 || nx > width || ny < 0 || ny > height) return make_pair(moved, false);
        
        //Is empty, can move
        if(graph[ny][nx] == '.'){
            swap(graph[start_y][start_x], graph[ny][nx]);
            start_x = nx;
            start_y = ny;
            moved = true;
        }
        //Goes into hole
        else if(graph[ny][nx] == 'O'){
            graph[start_y][start_x] = '.';
            moved = true;
            return make_pair(moved, true);
        }
        //Bumps onto something
        else{
            return make_pair(moved, false);
        }
    }
    return make_pair(false, false);
}

int simulate(vector<int> & dir, vector<string> graph){
    int red_x, red_y, blue_x, blue_y, hole_x, hole_y;
    for(int h = 0; h < height; h++){
        for(int w = 0; w < width; w++){
            if(graph[h][w] == 'R'){
                red_x = w;
                red_y = h;
            }
            if(graph[h][w] == 'B'){
                blue_x = w;
                blue_y = h;
            }
            if(graph[h][w] == 'O'){
                hole_x = w;
                hole_y = h;
            }
        }
    }
    
    int ans = 0;
    for(int current_dir : dir){
        ans += 1;
        bool red_hole = false;
        bool blue_hole = false;

        while(true){  
            //Moved, in hole
            pair<bool, bool> red = move(red_x, red_y, current_dir, graph);
            pair<bool, bool> blue = move(blue_x, blue_y, current_dir, graph);

            if(blue.second) blue_hole = true;
            if(red.second) red_hole = true;

            if(!blue.first && !red.first) break;
        }
        if(blue_hole) return -1;
        if(red_hole){
            return ans;
        }
    }
    return -1;
}

//Check if direction is valid
bool valid(vector<int> & dir){
    for(int i = 0; i < limit - 1; i++){
        if(dir[i] == 0 && dir[i+1] == 1) return false;
        if(dir[i] == 1 && dir[i+1] == 0) return false;
        if(dir[i] == 3 && dir[i+1] == 2) return false;
        if(dir[i] == 2 && dir[i+1] == 3) return false;
        if(dir[i] == dir[i+1]) return false;
    }
    return true;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> height >> width;
    vector<string> graph(height);

    for(int h = 0; h < height; h++){
        cin >> graph[h];
    }

    int ans = -1;
    for(int k = 0; k < (1<<(limit*2)); k++){
        vector<int> dir = generate(k);
        if(!valid(dir)) continue;
        //Get value using generated direction, update answer
        int current_value = simulate(dir, graph);
        if(current_value == -1) continue;
        if(ans == -1 || current_value < ans) ans = current_value;
    }
    cout << ans;

}


 
