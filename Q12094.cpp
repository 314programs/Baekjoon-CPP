#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

int n;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ans = 0;
int depth[11];

struct block{
    int num, comb;
};

int board[21][21];

bool compare(int(*temp)[21]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] != temp[i][j]) return true;
        }
    }
    return false;
}

void copy_board(int(*t)[21], int(*a)[21]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            *(t[i]+j) = *(a[i]+j);
        }
    }
}

int find_max(){
    int maximum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            maximum = max(maximum, board[i][j]);
        }
    }
    return maximum;
}

void move_loop(int dir){
    queue<int> q;

    //Right
    if(dir == 0){
        for(int i = 0; i < n; i++){
            for(int j = n-1; j >= 0; j--){
                if(board[i][j] != 0){
                    q.push(board[i][j]);
                    board[i][j] = 0;
                }
            }
            int idx = n-1;
            while(!q.empty()){
                int val = q.front();
                q.pop();

                if(board[i][idx] == 0) board[i][idx] = val;
                else if(board[i][idx] == val) board[i][idx--] += val;
                else board[i][--idx] += val;
            }
        }
    }

    //Left
    else if(dir == 1){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] != 0){
                    q.push(board[i][j]);
                    board[i][j] = 0;
                }
            }
            int idx = 0;
            while(!q.empty()){
                int val = q.front();
                q.pop();

                if(board[i][idx] == 0) board[i][idx] = val;
                else if(board[i][idx] == val) board[i][idx++] += val;
                else board[i][++idx] += val;
            }
        }
    }

    //Down
    else if(dir == 2){
        for(int j = 0; j < n; j++){
            for(int i = n-1; i >= 0; i--){
                if(board[i][j] != 0){
                    q.push(board[i][j]);
                    board[i][j] = 0;
                }
            }
            int idx = n-1;
            while(!q.empty()){
                int val = q.front();
                q.pop();

                if(board[idx][j] == 0) board[idx][j] = val;
                else if(board[idx][j] == val) board[idx--][j] += val;
                else board[--idx][j] = val;
            }
        }
    }
    //Up
    else{
        for(int j = 0; j < n; j++){
            for(int i = 0; i < n; i++){
                if(board[i][j] != 0){
                    q.push(board[i][j]);
                    board[i][j] = 0;
                }
            }
            int idx = 0;
            while(!q.empty()){
                int val = q.front();
                q.pop();

                if(board[idx][j] == 0) board[idx][j] = val;
                else if(board[idx][j] == val) board[idx++][j] += val;
                else board[++idx][j] = val;
            }
        }
    }
}

void backtrack(int idx){
    int now_max = find_max();
    if(idx == 10){
        if(now_max > ans){
            ans = now_max;
            for(int i = 10; i >= 0; i--){
                depth[i] = now_max;
                now_max /= 2;
            }
        }
        return;
    }

    if(depth[idx] >= now_max) return;
    int temp[21][21];

    for(int i = 0; i < 4; i++){
        copy_board(temp, board);
        move_loop(i);

        if(compare(temp)){
            backtrack(idx+1);
            copy_board(board, temp);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
            ans = max(ans, board[i][j]);
        }
    }

    memset(depth, -1, sizeof(depth));
    backtrack(0);
    cout << ans;

}
