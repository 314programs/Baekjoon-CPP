#include <bits/stdc++.h>
using namespace std;

struct city{
    bool special;
    int x, y;
};

struct node{
    int to, dist;
};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int inf = 1000000000;
    int city_num, teleport_time;
    cin >> city_num >> teleport_time;

    vector<city> c(city_num);
    map<int, vector<node>> m;

    int graph[city_num][city_num];

    for(int y = 0; y < city_num; y++){
        for(int x = 0; x < city_num; x++){
            if(y == x) graph[y][x] = 0;
            else graph[y][x] = inf;
        }
    }

    for(int i = 0; i < city_num; i++){
        bool s;
        int x_, y_;
        cin >> s >> x_ >> y_;
        c[i] = {s, x_, y_};
    }

    for(int i = 0; i < city_num; i++){
        for(int j = 0; j < city_num; j++){
            if(c[i].special == true && c[j].special == true){
                int temp = min(teleport_time, abs(c[i].x - c[j].x) + abs(c[i].y - c[j].y));
                graph[i][j] = min(temp, graph[i][j]);
            }
            else{
                graph[i][j] = min(abs(c[i].x - c[j].x) + abs(c[i].y - c[j].y), graph[i][j]);
            }
        }
    }

    for(int k = 0; k < city_num; k++){
        for(int a = 0; a < city_num; a++){
            for(int b = 0; b < city_num; b++){
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
            }
        }
    }

    int path_num;
    cin >> path_num;

    while(path_num--){
        int from, to;
        cin >> from >> to;
        cout << graph[from-1][to-1] << "\n";
    }

}
