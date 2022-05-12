#include <bits/stdc++.h>
using namespace std;

int graph[9][9];
vector<pair<int, int>> coordinates;

//Mark the visited using array instead of using functions each time
int square[9][10];
int column[9][10];
int row[9][10];

bool go(int idx){
    if(idx == coordinates.size()){
        return true;
    }
    for(int i = 1; i <= 9; i++){
        int y_ = coordinates[idx].first;
        int x_ = coordinates[idx].second;
        if(square[3*(y_/3) + (x_/3)][i] == 0 && row[y_][i] == 0 && column[x_][i] == 0){
            square[3*(y_/3) + (x_/3)][i] = 1;
            row[y_][i] = 1;
            column[x_][i] = 1;
            graph[y_][x_] = i;

            bool temp = go(idx+1);
            if(temp == true) return true;

            square[3*(y_/3) + (x_/3)][i] = 0;
            row[y_][i] = 0;
            column[x_][i] = 0;
        }
    }
    return false;

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    for(int y = 0; y < 9; y++){
        for(int x = 0; x < 9; x++){
            cin >> graph[y][x];
            if(graph[y][x] == 0){
                coordinates.push_back(make_pair(y, x));
            }
        }
    }
    
    //Setting up graphs
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

    for(int y = 0; y < 9; y++){
        for(int x = 0; x < 9; x++){
            cout << graph[y][x] << " ";
        }
        cout << "\n";
    }
}


