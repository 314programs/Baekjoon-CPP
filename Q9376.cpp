#include <bits/stdc++.h>
using namespace std;

char graph[102][102];
struct point{
    int x, y, doors;
};

int height, width;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

void bfs(point start, vector<vector<int>> & visited){
    deque<point> dq;
    dq.push_back(start);
    visited[start.y][start.x] = start.doors;

    while(!dq.empty()){
        point temp = dq.front();
        dq.pop_front();

        for(int i = 0; i < 4; i++){
            int ny = dy[i] + temp.y;
            int nx = dx[i] + temp.x;
            if(ny >= 0 && ny < height+2 && nx >= 0 && nx < width + 2 && graph[ny][nx] != '*'){
                int temp_val = temp.doors;
                if(graph[ny][nx] == '#') temp_val++;
                if(visited[ny][nx] == -1 || visited[ny][nx] > temp_val){
                    visited[ny][nx] = temp_val;
                    dq.push_back({nx, ny, temp_val});
                }
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int test_case;
    cin >> test_case;

    while(test_case--){
        cin >> height >> width;
        cin.ignore();

        point p_1 = {-1, -1, -1};
        point p_2 = {-1, -1, -1};   
        
        //Make graph height+2 * width+2 for extra space outside
        memset(graph, '.', sizeof(graph));
        for(int y = 0; y < height; y++){
            string temp;
            getline(cin, temp);
            for(int x = 0; x < width; x++){
                graph[y+1][x+1] = temp[x];
                if(graph[y+1][x+1] == '$' && p_1.x == -1){
                    p_1 = {x+1, y+1, 0};
                }
                else if(graph[y+1][x+1] == '$' && p_1.x != -1){
                    p_2 = {x+1, y+1, 0};
                }
            }
        }
        
        //Visited graph(measures how many doors opened) for each, oustide and 2 prisoners
        vector<vector<int>> outside(height+2, vector<int> (width+2, -1));
        vector<vector<int>> p_1_graph(height+2, vector<int> (width+2, -1));
        vector<vector<int>> p_2_graph(height+2, vector<int> (width+2, -1));

        bfs({0,0,0}, outside);
        bfs(p_1, p_1_graph);
        bfs(p_2, p_2_graph);

        int ans = 10001;
        for(int y = 0; y < height+2; y++){
            for(int x = 0; x < width+2; x++){
                if(graph[y][x] == '*' || outside[y][x] == -1 || p_1_graph[y][x] == -1 || p_2_graph[y][x] == -1) continue;
                int temp = outside[y][x] + p_1_graph[y][x] + p_2_graph[y][x];
                //Door already has been opened so -2
                if(graph[y][x] == '#') temp -= 2;
                ans = min(ans, temp);
            }
        }

        cout << ans << "\n";

    }
}
