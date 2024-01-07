#include <bits/stdc++.h>
using namespace std;

void draw(int height, vector<vector<char>> & graph, int start_x, int start_y){
    if(height == 3){
        graph[start_y][start_x + 2] = '*';
        graph[start_y+1][start_x + 1] = '*';
        graph[start_y+1][start_x + 3] = '*';

        for(int i = 0; i < 5; i++){
            graph[start_y+2][start_x+i] = '*';
        }
    }
    else{
        draw(height/2, graph, start_x + height/2, start_y);
        draw(height/2, graph, start_x, start_y + height/2);
        draw(height/2, graph, start_x + height, start_y + height/2);
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int height, width;
    cin >> height;
    width = (height*2) - 1;

    vector<vector<char>> board (height, vector<char> (width));

    draw(height, board, 0, 0);
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            if(board[y][x] == '*') cout << '*';
            else cout << ' ';
        }
        cout << "\n";
    }

}
