//Never use deque push_front for BFS... EVER
#include <bits/stdc++.h>
using namespace std;

string graph[1000];
int visited[1000][1000];
int expand[10];
int cnt[10];

struct node{
    int x, y, cnt;
};

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
vector<node> starts[10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    int height, width, ppl_cnt;
    cin >> height >> width >> ppl_cnt;

    memset(expand, 0, sizeof(expand));
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < ppl_cnt; i++){
        cin >> expand[i+1];
    }

    for(int y = 0; y < height; y++){
        cin >> graph[y];
    }
    
    memset(visited, -1, sizeof(visited));
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            if(graph[y][x] >= '1' && graph[y][x] <= '9'){
                starts[graph[y][x] - '0'].push_back({x, y, 0});
                visited[y][x] = graph[y][x] - '0';
            }
        }
    }
    
    //Made queue for each player
    queue<node> q[10];
    queue<node> nq[10];
    for(int i = 1; i <= ppl_cnt; i++){
        for(node ch: starts[i]){
            q[i].push(ch);
        }
    }
    
    //While they can move
    while(true){
        bool can = false;
        //For each player
        for(int i = 1; i <= ppl_cnt; i++){
            while(!q[i].empty()){
                node current = q[i].front();
                q[i].pop();

                for(int j = 0; j < 4; j++){
                    int nx = dx[j] + current.x;
                    int ny = dy[j] + current.y;
                    
                    if(nx >= 0 && nx < width && ny >= 0 && ny < height && graph[ny][nx] == '.' && visited[ny][nx] == -1){
                        if(current.cnt < expand[i]-1){
                            q[i].push({nx, ny, current.cnt+1});
                        }
                        else{
                            nq[i].push({nx, ny, 0});
                        }
                        can = true;
                        visited[ny][nx] = i;
                    }
                }
            }
            //Update queue
            q[i] = nq[i]; 
            nq[i] = queue<node>();
        }

        if(!can) break;
    }
    
    //Count spaces
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            if(visited[y][x] != -1){
                cnt[visited[y][x]]++;
            }
        }
    }

    for(int i = 1; i <= ppl_cnt; i++){
        std::cout << cnt[i] << " ";
    }

}
