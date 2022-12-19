//Could have done it more simply by using functions... but found this to be faster

#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

int height, width;
int graph[100][100];
int dx[6] = {1, -1, 0, 1, 0, 1};
int dy[6] = {0, 0, 1, 1, -1, -1};

struct point{
    int x, y;
};

//BFS + perimeter calculation
int bfs(int x, int y, int mark){
    point start = {x, y};
    queue<point> q;
    graph[start.y][start.x] = mark;
    q.push(start);
    int peri = 0;

    while(!q.empty()){
        //Initial perimeter of the shape is assumed to be 6
        //However, when it has areas of contact, perimeter will be subtracted accordingly
        peri += 6;
        point current = q.front();
        q.pop();
        
        for(int i = 0; i < 6; i++){
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];
            
            //This was confusing
            if(current.y%2 != 0 && i > 1){
                nx--;
            }
            
            if(nx >= 0 && nx < width && ny >= 0 && ny < height){
                if(graph[ny][nx] == 1){
                    peri--;
                    graph[ny][nx] = mark;
                    q.push({nx, ny});
                }
                else if(graph[ny][nx] > 1 || graph[ny][nx] == 0){
                    peri--;
                }
            }
        }
    }
    return peri;

}

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    
    cin >> width >> height;
    memset(graph, 0, sizeof(graph));
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            cin >> graph[i][j];
        }
    }
    
    //Mark the outer buildings
    //One inside does not need to be counted so...
    int ans = 0;
    int mark = 2;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if((i == 0 || i == height-1 || j == 0 || j == width-1) && graph[i][j] == 0){
                point start = {j, i};
                queue<point> q;
                graph[start.y][start.x] = -1;
                q.push(start);

                while(!q.empty()){
                    point current = q.front();
                    q.pop();
                    
                    for(int k = 0; k < 6; k++){
                        int nx = current.x + dx[k];
                        int ny = current.y + dy[k];

                        if(current.y%2 != 0 && k > 1){
                            nx--;
                        }
                        
                        if(nx >= 0 && nx < width && ny >= 0 && ny < height && graph[ny][nx] == 0){
                            graph[ny][nx] = -1;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }
    
    //Do BFS to calculate perimeter
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(graph[i][j] == 1){
                ans += bfs(j, i, mark++);
            }
        }
    }


    cout << ans;

}
