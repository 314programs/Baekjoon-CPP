#include <bits/stdc++.h>
using namespace std;

int height, width;
struct point{
    int x, y;
};

bool ok(point p){
    return p.x >= 0 && p.x < width && p.y >= 0 && p.y < height;
}

int mark(point p, vector<vector<char>> & graph, int size){
    if(!ok({p.x, p.y + size}) || graph[p.y + size][p.x] == '.') return -1;
    if(!ok({p.x, p.y - size}) || graph[p.y - size][p.x] == '.') return -1;
    if(!ok({p.x + size, p.y}) || graph[p.y][p.x + size] == '.') return -1;
    if(!ok({p.x - size, p.y}) || graph[p.y][p.x - size] == '.') return -1;

    graph[p.y + size][p.x] = '.';
    graph[p.y - size][p.x] = '.';
    graph[p.y][p.x + size] = '.';
    graph[p.y][p.x - size] = '.';
    return 1;
}

int solve(vector<vector<char>> graph, point u, point v){
    int u_size = 0, v_size = 0;
    while(true){
        int u_mark = mark(u, graph, u_size);
        int v_mark = mark(v, graph, v_size);
        if(u_mark == -1 && v_mark == -1) break;

        if(u_mark == 1) u_size++;
        if(v_mark == 1) v_size++;
    }
    if(u_size == 0 || v_size == 0) return -1;
    return (1+((u_size-1)*4))*(1+((v_size-1)*4));
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> height >> width;
    cin.ignore();

    vector<vector<char>> graph(height, vector<char> (width));
    int area = height*width;
    vector<point> coords(area);

    int idx = 0;
    for(int y = 0; y < height; y++){
        string temp;
        getline(cin, temp);
        for(int x = 0; x < width; x++){
            coords[idx++] = {x, y};
            graph[y][x] = temp[x];
        }
    }

    int ans = 0;
    for(int i = 0; i < area-1; i++){
        for(int j = i+1; j < area; j++){
            ans = max(solve(graph, coords[i], coords[j]), ans);
        }
    }
    cout << ans;

}
