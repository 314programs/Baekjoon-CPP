#include <bits/stdc++.h>
using namespace std;

int graph[1000][1000];

void add_num(string &ans, char direction, int count){
    for(int i = 0; i < count; i++){
        ans += direction;
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int height, width;
    cin >> height >> width;

    string ans;

    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            cin >> graph[y][x];
        }
    }

    if(height%2 == 1){
        for(int i = 1; i < height; i++){
            if(i%2 == 1){
                add_num(ans, 'R', width - 1);
                add_num(ans, 'D', 1);
            }
            else if(i%2 == 0){
                add_num(ans, 'L', width - 1);
                add_num(ans, 'D', 1);
            }
        }
        add_num(ans, 'R', width - 1);
    }

    else if(height%2 == 0 && width%2 == 1){
        for(int i = 1; i < width; i++){
            if(i%2 == 1){
                add_num(ans, 'D', height-1);
                add_num(ans, 'R', 1);
            }
            else if(i%2 == 0){
                add_num(ans, 'U', height-1);
                add_num(ans, 'R', 1);
            }
        }
        add_num(ans, 'D', height-1);
    }

    else if(height%2 == 0 && width%2 == 0){
        int min_x = 0, min_y = 1;

        for(int y = 0; y < height; y++){
            for(int x = 0; x < width; x++){
                if(graph[y][x] < graph[min_y][min_x] && (y+x)%2 == 1){
                    min_x = x;
                    min_y = y;
                }
            }
        }

        int start_x = 0, start_y = 0;
        int end_x = width-1, end_y = height-1;
        string ans_2;
        
        while(abs(end_y - start_y) > 1){
            if(min_y/2 > start_y/2){
                add_num(ans, 'R', width-1);
                add_num(ans, 'D', 1);
                add_num(ans, 'L', width-1);
                add_num(ans, 'D', 1);
                start_y += 2;
            }
            if(min_y/2 < end_y/2){
                add_num(ans_2, 'R', width-1);
                add_num(ans_2, 'D', 1);
                add_num(ans_2, 'L', width-1);
                add_num(ans_2, 'D', 1);
                end_y -= 2;
            }
        }

        while(abs(end_x - start_x) > 1){
            if(min_x/2 > start_x/2){
                add_num(ans, 'D', 1);
                add_num(ans, 'R', 1);
                add_num(ans, 'U', 1);
                add_num(ans, 'R', 1);
                start_x += 2;
            }
            if(min_x/2 < end_x/2){
                add_num(ans_2, 'D', 1);
                add_num(ans_2, 'R', 1);
                add_num(ans_2, 'U', 1);
                add_num(ans_2, 'R', 1);
                end_x -= 2;
            }
        }
        
        if(min_y == start_y){
            add_num(ans, 'D', 1);
            add_num(ans, 'R', 1);
        }
        else if(min_y == end_y){
            add_num(ans, 'R', 1);
            add_num(ans, 'D', 1);
        }
        reverse(ans_2.begin(), ans_2.end());
        ans += ans_2;


    }
    cout << ans;

}
