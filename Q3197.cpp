#include <bits/stdc++.h>
using namespace std;

string graph[1500];
bool visited_w[1500][1500];
bool visited_s[1500][1500];

struct node{
    int x, y;
};

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int height, width;
    cin >> height >> width;

    for(int y = 0; y < height; y++){
        cin >> graph[y];
    }

    node swan_s = {-1, -1}, swan_e = {-1, -1};
    memset(visited_w, false, sizeof(visited_w));
    memset(visited_s, false, sizeof(visited_s));

    queue<node> swan_q, water_q, new_swan_q, new_water_q;
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            //Water
            if(graph[y][x] == '.'){
                water_q.push({x, y});
                visited_w[y][x] = true;
            }

            //Swan
            if(graph[y][x] == 'L' && swan_s.x == -1){
                swan_s = {x, y};
                swan_q.push({x, y});
                visited_s[y][x] = true;
                visited_w[y][x] = true;
                //Swans are inside water
                water_q.push({x, y});
            }
            else if(graph[y][x] == 'L'){
                swan_e = {x, y};
                visited_w[y][x] = true;
                water_q.push({x, y});
            }
        }
    }

    for(int i = 0;; i++){
        //Swan
        while(!swan_q.empty()){
            node current = swan_q.front();
            swan_q.pop();
            
            for(int i = 0; i < 4; i++){
                int nx = current.x + dx[i];
                int ny = current.y + dy[i];
                if(nx >= 0 && nx < width && ny >= 0 && ny < height && visited_s[ny][nx] == false){
                    if(visited_w[ny][nx] == true){
                        visited_s[ny][nx] = true;
                        swan_q.push({nx, ny});
                    }
                    else{
                        //For the next second
                        visited_s[ny][nx] = true;
                        new_swan_q.push({nx, ny});
                    }
                }
            }
        }

        swan_q = new_swan_q;
        new_swan_q = queue<node>();

        if(visited_s[swan_e.y][swan_e.x] == true){
            cout << i;
            break;
        }


        //Water
        while(!water_q.empty()){
            node current = water_q.front();
            water_q.pop();

            for(int i = 0; i < 4; i++){
                int nx = current.x + dx[i];
                int ny = current.y + dy[i];
                if(nx >= 0 && nx < width && ny >= 0 && ny < height){
                    if(visited_w[ny][nx] == false){
                        visited_w[ny][nx] = true;
                        new_water_q.push({nx, ny});
                    }
                }
            }
        }

        water_q = new_water_q;
        new_water_q = queue<node>();

    }

}
