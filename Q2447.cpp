#include <bits/stdc++.h>
using namespace std;

void draw(vector<vector<char>> & graph, int dimension, int start_x, int start_y){
    if(dimension == 1) return;

    if(dimension == 3){
        int th = 0;
        for(int y = 0; y < 3; y++){
            for(int x = 0; x < 3; x++){
                if(th != 4) graph[y+start_y][x+start_x] = '*';
                th++;
            }
        }
    }
    else{
        int th = 0;
        for(int y = 0; y < 3; y++){
            for(int x = 0; x < 3; x++){
                if(th != 4) draw(graph, dimension/3, start_x + (x*(dimension/3)), start_y + (y*(dimension/3)));
                th++;
            }
        }
    }
    
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int dimension;
    cin >> dimension;
    
    vector<vector<char>> board (dimension, vector<char>(dimension));

    draw(board, dimension, 0, 0);

    for(int y = 0; y < dimension; y++){
        for(int x = 0; x < dimension; x++){
            if(board[y][x] == '*') cout << board[y][x];
            else cout << " ";
        }
        cout << "\n";
    }
}
