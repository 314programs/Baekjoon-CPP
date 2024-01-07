#include <bits/stdc++.h>
using namespace std;

int height, width;
int visited[50][50];
char graph[50][50];

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

//Search depth
bool DFS(int start_x, int start_y, char color, int distance){
    //Checking if cycle is not self repeated
    if(visited[start_y][start_x] != 0){
        return abs(distance - visited[start_y][start_x]) + 1 >= 4;
    }

    visited[start_y][start_x] = distance + 1;


    for(int i = 0; i < 4; i++){
        int new_x = dx[i] + start_x;
        int new_y = dy[i] + start_y;

        if(new_x < width && new_x >= 0 && new_y < height && new_y >= 0 && graph[new_y][new_x] == color){
            if(DFS(new_x, new_y, color, distance + 1)) return true;
        }
    }

    return false;

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> height >> width;
    cin.ignore();

    for(int i = 0; i < height; i++){
        string temp;
        getline(cin, temp);
        for(int j = 0; j < width; j++){
            graph[i][j] = temp[j];
        }
    }
    string answer = "No";
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            memset(visited, 0, sizeof(visited));
            if(DFS(j, i, graph[i][j], 0)) answer = "Yes";
        }
    }

    cout << answer;
    
}

