#include <bits/stdc++.h>
using namespace std;

int graph[300][300];
int vertical_num, horizontal_num, placement_num;
int ans = 10;

int follow_line(int line_num){
    int x_ = line_num, y_ = 0;
    for(int y = 0; y < horizontal_num; y++){
        if(graph[y_][x_] == 1 && graph[y_][x_+1] == 2) x_++;
        else if(graph[y_][x_] == 2 && graph[y_][x_-1] == 1) x_--;
        y_++;
    }
    return x_;
}

bool check(){
    for(int i = 0; i < vertical_num; i++){
        if(follow_line(i) != i){
            return false;
        }
    }
    return true;
}

void combinations(int count_, int x_start, int y_start){
    if(count_ == 4){
        return;
    }
    if(check() == true){
        ans = min(count_, ans);
    }

    for(int y = y_start; y < horizontal_num; y++){
        for(int x = 0; x < vertical_num - 1; x++){
            if(graph[y][x] == 0 && graph[y][x+1] == 0){
                graph[y][x] = 1;
                graph[y][x+1] = 2;
                combinations(count_ + 1, x, y);
                graph[y][x] = 0;
                graph[y][x+1] = 0;
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> vertical_num >> placement_num >> horizontal_num;
    memset(graph, 0, sizeof(graph));

    for(int i = 0; i < placement_num; i++){
        int place_x, place_y;
        cin >> place_y >> place_x;
        graph[place_y-1][place_x-1] = 1;
        graph[place_y-1][place_x] = 2;
    }

    combinations(0, 0, 0);
    if(ans == 10) cout << -1;
    else cout << ans;


}
