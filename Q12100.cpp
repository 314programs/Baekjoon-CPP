#include <bits/stdc++.h>
using namespace std;

int dimension;

vector<int> generate(int k){
    vector<int> new_dir(5);
    for(int i = 0; i < 5; i++){
        new_dir[i] = (k&3);
        k >>= 2;
    }
    return new_dir;
}

int move(vector<vector<pair<int, int>>> & graph, int direction, int start_x, int start_y, int visit_mark){
    int moved = 0;
    while(true){
        int nx = start_x;
        int ny = start_y;
        
        //Up
        if(direction == 0) ny -= 1;
        //Down
        else if(direction == 1) ny += 1;
        //Right
        else if(direction == 2) nx += 1;
        //Left
        else if(direction == 3) nx -= 1;

        //Blocked by dimension of board
        if(ny < 0 || ny >= dimension || nx < 0 || nx >= dimension) break;
        //Can move
        if(graph[ny][nx].first == 0){
            swap(graph[ny][nx], graph[start_y][start_x]);
            start_x = nx;
            start_y = ny;
            moved += 1;
        }
        else if(graph[ny][nx].first != 0){
            //Merge, make sure both elements did not merge yet
            if(graph[ny][nx].first == graph[start_y][start_x].first && graph[ny][nx].second != visit_mark && graph[start_y][start_x].second != visit_mark){
                graph[ny][nx].first += graph[start_y][start_x].first;
                graph[ny][nx].second = visit_mark;
                graph[start_y][start_x] = make_pair(0, 0);
                moved += 1;
            }

            //Blocked
            else{
                break;
            }
        }

    }
    return moved;
}

int simulate(vector<vector<pair<int, int>>> graph, vector<int> directions){
    int move_round = 0;
    for(int dir: directions){
        move_round += 1;
        while (true){
            int moved = 0;
            
            //Search method for each direction is different as there are different priorities for each direction...
            if(dir == 0){
                for(int y = 0; y < dimension; y++){
                    for(int x = 0; x < dimension; x++){
                        if(graph[y][x].first != 0) moved += move(graph, dir, x, y, move_round);
                    }
                }
            }
            if(dir == 1){
                for(int y = dimension - 2; y >= 0; y--){
                    for(int x = 0; x < dimension; x++){
                        if(graph[y][x].first != 0) moved += move(graph, dir, x, y, move_round);
                    }
                }
            }
            if(dir == 2){
                for(int y = 0; y < dimension; y++){
                    for(int x = dimension - 1; x >= 0 ; x--){
                        if(graph[y][x].first != 0) moved += move(graph, dir, x, y, move_round);
                    }
                }
            }
            if(dir == 3){
                for(int y = 0; y < dimension; y++){
                    for(int x = 0; x < dimension; x++){
                        if(graph[y][x].first != 0) moved += move(graph, dir, x, y, move_round);
                    }
                }
            }
            if(moved == 0) break;
        }
    }

    int maximum = 0;

    for(int y = 0; y < dimension; y++){
        for(int x = 0; x < dimension; x++){
            maximum = max(maximum, graph[y][x].first);
        }
    }
    return maximum;
}

int main(void){
    cin >> dimension;
    
    //first: number stored, second: if have merged
    vector<vector<pair<int, int>>> graph(dimension, vector<pair<int, int>> (dimension));
    for(int y = 0; y < dimension; y++){
        for(int x = 0; x < dimension; x++){
            int temp;
            cin >> temp;
            graph[y][x] = make_pair(temp, 0);
        }
    }

    int ans = 0;

    for(int i = 0; i < (1 << (5 * 2)); i++){
        vector<int> current_dir = generate(i);
        ans = max(simulate(graph, current_dir), ans);
    }
    cout << ans;
}


 
