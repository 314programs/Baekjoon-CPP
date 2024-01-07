#include <bits/stdc++.h>
using namespace std;

char graph[20][20];
int visited[20][20];
int height, width;

int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

int coin1_x, coin1_y, coin2_x, coin2_y; 

int calc(int x1, int y1, int x2, int y2, int count_){
    if(count_ == 11) return -1;
    bool coin1_fall, coin2_fall; 
    coin1_fall = false; 
    coin2_fall = false;

    if(x1 < 0 || x1 >= width || y1 < 0 || y1 >= height) coin1_fall = true;
    if(x2 < 0 || x2 >= width || y2 < 0 || y2 >= height) coin2_fall = true;

    if(coin1_fall && coin2_fall) return -1;
    if(coin1_fall || coin2_fall){
        return count_;
    }

    int ans = -1;
    
    //DFS 
    for(int i = 0; i < 4; i++){
        int new_x1 = dx[i] + x1;
        int new_y1 = dy[i] + y1;
        int new_x2 = dx[i] + x2;
        int new_y2 = dy[i] + y2;
        //It doesn't move when encountering a wall
        if(new_x1 >= 0 && new_x1 < width && new_y1 >= 0 && new_y1 < height && graph[new_y1][new_x1] == '#'){
            new_x1 = x1;
            new_y1 = y1;
        }
        //Mistyping x2 as y2 cost me 2 hours to find...
        if(new_x2 >= 0 && new_x2 < width && new_y2 >= 0 && new_y2 < height && graph[new_y2][new_x2] == '#'){
            new_x2 = x2;
            new_y2 = y2;
        }
        int temp = calc(new_x1, new_y1, new_x2, new_y2, count_+1);
        if(temp == -1) continue;
        if(ans == -1 || ans > temp){
            ans = temp;
        }
    }
    return ans;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    coin1_x = -1;
    cin >> height >> width;
    cin.ignore();

    for(int y = 0; y < height; y++){
        string temp;
        getline(cin, temp);
        for(int x = 0; x < width; x++){
            graph[y][x] = temp[x];
            if(graph[y][x] == 'o'){
                graph[y][x] = '.';
                if(coin1_x == -1){
                    coin1_x = x;
                    coin1_y = y;
                }
                else{
                    coin2_x = x;
                    coin2_y = y;
                }
            }
        }
    }

    cout << calc(coin1_x, coin1_y, coin2_x, coin2_y, 0);
}


