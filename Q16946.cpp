#include <bits/stdc++.h>
using namespace std;

int height, width;
int graph[1001][1001];
int visited[1001][1001];

int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
int can_go[1000000];

//Mark visited for cells that can be visited without breaking wall
//Mark them seperately and put count of the cells in can_go
int BFS(int mark, int x, int y){
    queue<pair<int, int>> q_;
    q_.push(make_pair(y, x));
    visited[y][x] = mark;

    int count_ = 1;

    while(!q_.empty()){
        int temp_x = q_.front().second;
        int temp_y = q_.front().first;
        q_.pop();

        for(int i = 0; i < 4; i++){
            int ny = temp_y + dy[i];
            int nx = temp_x + dx[i];

            if(ny < 0 || ny >= height || nx < 0 || nx >= width) continue;
            if(visited[ny][nx] == -1){
                visited[ny][nx] = mark;
                count_ += 1;
                q_.push(make_pair(ny, nx));
            }
        }
    }
    return count_;
}

//Get a set of marks which returns how many cells can be visited
int count_can_go(int x, int y){
    int set_marked[4] = {-1, -1, -1, -1};
    int total = 1;

    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= height || nx < 0 || nx >= width) continue;

        int new_mark = visited[ny][nx];
        if(new_mark <= 0) continue;
        set_marked[i] = new_mark;
         
        //Seeing if a group re-appears
        for(int j = 0; j < i; j++){
            if(set_marked[i] == set_marked[j]){
                set_marked[i] = 0;
            }
        }
        
        total += can_go[set_marked[i]];
    }
    //Return total%10 to print
    return (total)%10;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> height >> width;
    
    memset(visited, -1, sizeof(visited));
    cin.ignore();
    
    //Input
    for(int y = 0; y < height; y++){
        string temp;
        getline(cin, temp);
        for(int x = 0; x < width; x++){
            graph[y][x] = temp[x] - '0';
            if(graph[y][x] == 1){
                visited[y][x] = -2;
            }
        }
    }
    
    //Marking visited cells (0 only)
    int mark = 1;
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            if(graph[y][x] == 0 && visited[y][x] == -1){
                can_go[mark] = BFS(mark, x, y);
                mark++;
            }
        }
    }
    
    //Print
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            if(graph[y][x] == 1){
                cout << count_can_go(x, y);
            }
            else{
                cout << graph[y][x];
            } 
        }
        cout << "\n";
    }

}


 
