//This is... silver?
//Simulation can get confusing, I think...

#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

#define inf 2e9

int graph[50][50];
int n, m, t;

//These bools determine when spiral passed through the wanted parts of the graph
bool left_up = false, left_down = false, right_up = false, right_down = false;

struct spiral{
    int x, y, way;
};

struct point{
    int x, y;
};

void place(point p, int &num){
    //Check the bools, and check if the point that is about to be placed within boundaries
    if(p.x <= 0 && p.y <= 0) left_up = true;
    if(p.x <= 0 && p.y >= n-1) left_down = true;
    if(p.x >= m-1 && p.y <= 0) right_up = true;
    if(p.x >= m-1 && p.y >= n-1) right_down = true;

    if(p.x >= 0 && p.x < m && p.y >= 0 && p.y < n){
        graph[p.y][p.x] = min(graph[p.y][p.x], num+1);
    }
    num++;
}

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> n >> m >> t;
    
    //Input and memset
    vector<spiral> a(t);
    for(int i = 0; i < t; i++){
        cin >> a[i].y >> a[i].x >> a[i].way;
        a[i].x--;
        a[i].y--;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            graph[i][j] = inf;
        }
    }

    for(spiral sp: a){
        int step = 1;
        int change = 1;
        point cur = {sp.x, sp.y};
        graph[sp.y][sp.x] = 1;
        left_up = false, left_down = false, right_up = false, right_down = false;

        while(left_up+left_down+right_up+right_down != 4){
            //Upwards
            for(int i = 0; i < step; i++){
                cur.y--;
                place(cur, change);
            }
            
            //Left or right
            for(int i = 0; i < step; i++){
                if(sp.way == 0) cur.x++;
                if(sp.way == 1) cur.x--;
                place(cur, change);
            }
            step++;
            
            //Downwards
            for(int i = 0; i < step; i++){
                cur.y++;
                place(cur, change);
            }
            
            //Left or right
            for(int i = 0; i < step; i++){
                if(sp.way == 0) cur.x--;
                if(sp.way == 1) cur.x++;
                place(cur, change);
            }
            step++;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }


}
