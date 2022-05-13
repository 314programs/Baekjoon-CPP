#include <bits/stdc++.h>
using namespace std;

int graph[9][9];

int square[9][10];
int column[9][10];
int row[9][10];
int domino[10][10];

//Turning direction of domino
int dy[2] = {0, 1};
int dx[2] = {1, 0};

//Function for checking if number can be placed
bool check_(int y_, int x_, int num){
    if(square[3*(y_/3) + (x_/3)][num] != 0){
        return false;
    }
    if(row[y_][num] != 0){ 
        return false;
    }
    if(column[x_][num] != 0){
        return false;
    }
    return true;
}

//Function for marking spots
void mark_(int y_, int x_, int num, int mark_val){
    graph[y_][x_] = num;
    square[3*(y_/3) + (x_/3)][num] = mark_val;
    row[y_][num] = mark_val;
    column[x_][num] = mark_val;
}

bool go(int idx){
    if(idx == 81){
        return true;
    }

    int y_ = idx/9;
    int x_ = idx%9;
     
    //Mistake was made here, instead of go(idx+1), value should be returned so that the program knows when to exit
    if(graph[y_][x_] != 0) return go(idx+1);
    
    //Loop for turning domino
    for(int dir = 0; dir < 2; dir++){
        int ny_ = y_ + dy[dir];
        int nx_ = x_ + dx[dir];

        if(graph[y_][x_] != 0 || graph[ny_][nx_] != 0) continue;
        if(ny_ > 9 || nx_ > 9) continue;
        
        //Loop for 2 numbers on domino
        for(int i = 1; i <= 9; i++){
            for(int j = 1; j <= 9; j++){
                if(check_(y_, x_, i) && check_(ny_, nx_, j) && i != j && domino[i][j] == 0 && domino[j][i] == 0){
                    mark_(y_, x_, i, 1);
                    mark_(ny_, nx_, j, 1);
                    //Mark used domino
                    domino[i][j] = 1;
                    domino[j][i] = 1;
                    
                    bool temp = go(idx+1);
                    if(temp == true) return true;

                    mark_(y_, x_, i, 0);
                    mark_(ny_, nx_, j, 0);
                    graph[y_][x_] = 0;
                    graph[ny_][nx_] = 0;
                    domino[i][j] = 0;
                    domino[j][i] = 0;
                }
            }
        }
    }
    return false;
}

void convert_domino(int num, string pos){
    int row = pos[0] - 'A';
    int column = pos[1] - '0' - 1;
    graph[row][column] = num;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int puzzle_count = 1;
    int dominos_filled;
    while(true){
        cin >> dominos_filled;
        if(dominos_filled == 0){
            break;
        }
         
        //Reset values
        memset(graph, 0, sizeof(graph));
        memset(domino, 0, sizeof(domino));
        memset(square, 0, sizeof(square));
        memset(row, 0, sizeof(row));
        memset(column, 0, sizeof(column));
        
        //Input for placed dominos
        for(int i = 0; i < dominos_filled; i++){
            int d_num1, d_num2;
            string d_pos1, d_pos2;
            cin >> d_num1 >> d_pos1 >> d_num2 >> d_pos2;
            domino[d_num1][d_num2] = 1;
            domino[d_num2][d_num1] = 1;
            convert_domino(d_num1, d_pos1);
            convert_domino(d_num2, d_pos2);
        }
        
        //Filled in 9 numbers
        for(int i = 1; i <= 9; i++){
            string num_pos;
            cin >> num_pos;
            convert_domino(i, num_pos);
        }
        
        //Arrays to check if spot if available
        for(int y = 0; y < 9; y++){
            for(int x = 0; x < 9; x++){
                row[y][graph[y][x]] = 1;
            }
        }

        for(int x = 0; x < 9; x++){
            for(int y = 0; y < 9; y++){
                column[x][graph[y][x]] = 1;
            }
        }

        for(int y = 0; y < 9; y++){
            for(int x = 0; x < 9; x++){
                square[(x/3) + (y/3)*3][graph[y][x]] = 1;
            }
        }

        go(0);
        
        //Print answer
        cout << "Puzzle " << puzzle_count << "\n";
        for(int y = 0; y < 9; y++){
            for(int x = 0; x < 9; x++){
                cout << graph[y][x];
            }
            cout << "\n";
        }
        puzzle_count += 1;
    }

}


 
