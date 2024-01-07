#include <bits/stdc++.h>
using namespace std;

struct point{
    int x, y;
};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int dimension;
    cin >> dimension;
    cin.ignore();

    vector<string> graph(dimension);
    for(int y = 0; y < dimension; y++){
        string temp;
        getline(cin, temp);
        graph[y] = temp;
    }

    int start = -1, end = -1;
    vector<vector<int>> mirror_num(dimension, vector<int> (dimension, -1));
    vector<point> mirrors;
  
    //Number mirrors, mark them on the graph
    //Also append them into vector<point> mirrors
    for(int y = 0; y < dimension; y++){
        for(int x = 0; x < dimension; x++){
            if(graph[y][x] == '#'){
                if(start == -1){
                    start = mirrors.size();
                }
                else{
                    end = mirrors.size();
                }
                mirror_num[y][x] = mirrors.size();
                mirrors.push_back({x, y});
            }
            else if(graph[y][x] == '!'){
                mirror_num[y][x] = mirrors.size();
                mirrors.push_back({x, y});
            }
        }
    }

    int mirror_count = mirrors.size();
    vector<vector<bool>> can_go(mirror_count, vector<bool> (mirror_count, false));

    int dy[4] = {0,0,1,-1};
    int dx[4] = {1,-1,0,0};
    
    //Mark if it is possible to travel from one numbered mirror to another
    for(int i = 0; i < mirror_count; i++){
        point temp_m = mirrors[i];
        for(int j = 0; j < 4; j++){
            int ny = temp_m.y + dy[j];
            int nx = temp_m.x + dx[j];
            while(ny >= 0 && ny < dimension && nx >= 0 && nx < dimension){
                if(graph[ny][nx] == '*') break;
                if(mirror_num[ny][nx] != -1){
                    can_go[i][mirror_num[ny][nx]] = true;
                }
                ny += dy[j];
                nx += dx[j];
            }
        }
    }

    queue<int> q;
    vector<int> dist(mirror_count, -1);
    q.push(start);
    dist[start] = 0;
    
    //Dijkstra... I forgot how to use it properly
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = 0; i < mirror_count; i++){
            if(can_go[now][i] && dist[i] == -1){
                dist[i] = dist[now]+1;
                q.push(i);
            }
        }
    }

    cout << dist[end]-1;



}
