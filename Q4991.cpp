//Annoying simulation
#include <bits/stdc++.h>
using namespace std;

int width, height;
char graph[20][20];
int visited[20][20];
int from_to[12][12];
int dirty_spot_idx[20][20];

int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

struct point{
    int x, y;
};

void bfs_dist(point origin, int idx){
    //Visit all dirty spots/vaccum and save its distance
    memset(visited, -1, sizeof(visited));
    queue<point> q;
    q.push(origin);
    visited[origin.y][origin.x] = 0;

    while(!q.empty()){
        point temp = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int ny = temp.y + dy[i];
            int nx = temp.x + dx[i];
            if(ny >= 0 && ny < height && nx >= 0 && nx < width && visited[ny][nx] == -1 && graph[ny][nx] != 'x'){
                visited[ny][nx] = visited[temp.y][temp.x] + 1;
                if(graph[ny][nx] == '*'){
                    from_to[idx][dirty_spot_idx[ny][nx]] = visited[ny][nx];
                }
                if(graph[ny][nx] == 'o'){
                    from_to[idx][0] = visited[ny][nx];
                }
                q.push({nx, ny});
            }
        }
    }
}

int calc_dist(vector<int> & permu){
    int n = permu.size();
    if(from_to[0][permu[0]] == 0) return 0;
    //Start visiting from vaccum
    int ans = from_to[0][permu[0]];
    for(int i = 1; i < n; i++){
        //If the distance = 0, meaning that it cannot be visited return 0
        if(from_to[permu[i-1]][permu[i]] == 0) return 0;
        ans += from_to[permu[i-1]][permu[i]];
    }
    return ans;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    while(true){
        //Input
        memset(from_to, 0, sizeof(from_to));
        memset(dirty_spot_idx, 0, sizeof(dirty_spot_idx));

        int dirty_spot_count = 0;
        map<int, point> dirty_spot;
        point original_point;

        cin >> width >> height;
        if(width == 0 && height == 0) break;
        cin.ignore();

        for(int y = 0; y < height; y++){
            string temp;
            getline(cin, temp);
            for(int x = 0; x < width; x++){
                graph[y][x] = temp[x];
                if(graph[y][x] == 'o') original_point = {x, y};
            }
        }

        dirty_spot[0] = original_point;
        
        for(int y = 0; y < height; y++){
            for(int x = 0; x < width; x++){
                if(graph[y][x] == '*'){
                    dirty_spot_count++;
                    //Store point in a map for later use in calculating distance
                    dirty_spot[dirty_spot_count] = {x, y};
                    dirty_spot_idx[y][x] = dirty_spot_count;
                }
            }
        }

        for(int from = 0; from <= dirty_spot_count; from++){
            bfs_dist(dirty_spot[from], from);
        }

        vector<int> permu(dirty_spot_count);
        for(int i = 0; i < dirty_spot_count; i++) permu[i] = i+1;
        int ans = -1;
        
        //In which order to visit
        do{
            int temp_ans = calc_dist(permu);
            if(temp_ans != 0 && (ans == -1 || temp_ans < ans)){
                ans = temp_ans;
            }
        }
        while(next_permutation(permu.begin(), permu.end()));
        cout << ans << "\n";

    }

}
