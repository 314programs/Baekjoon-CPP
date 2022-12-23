//This hurts my brain
//I had to solve it THE DIFFICULT WAY AGAIN

#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

int n, k;

struct pawn{
    int x, y;
    int dir;
};

struct board{
    int color;
    vector<int> check;
};

map<int, pawn> m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
board graph[15][15];

int reverse_dir(int dir){
    if(dir == 0) return 1;
    else if(dir == 1) return 0;
    else if(dir == 2) return 3;
    else return 2;
}

bool solve(int t){
    //Reversing the direction
    //This one was confusing because I was confused on how the question wants me to react to being blocked in double sides
    //Looked at the correct code, just stay there
    int nx = m[t].x + dx[m[t].dir];
    int ny = m[t].y + dy[m[t].dir];
    if(!(nx >= 0 && nx < n && ny >= 0 && ny < n) || graph[ny][nx].color == 2){
        m[t].dir = reverse_dir(m[t].dir);
        nx = m[t].x + dx[m[t].dir];
        ny = m[t].y + dy[m[t].dir];
    }

    if(!(nx >= 0 && nx < n && ny >= 0 && ny < n) || graph[ny][nx].color == 2){
        return false;
    }

    vector<int> movement;
    int temp = -1;
    
    //Trasportation of pawns
    while(temp != t){
        temp = graph[m[t].y][m[t].x].check.back();
        movement.push_back(graph[m[t].y][m[t].x].check.back());
        graph[m[t].y][m[t].x].check.pop_back();
    }

    if(graph[ny][nx].color == 0){
        reverse(movement.begin(), movement.end());
    }
    
    //Updating locations and vectors
    for(auto ch: movement){
        m[ch].x = nx;
        m[ch].y = ny;
        graph[ny][nx].check.push_back(ch);
        if(graph[ny][nx].check.size() >= 4) return true;
    }

    return false;

}

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j].color;
        }
    }
    
    for(int i = 0; i < k; i++){
        int y, x, direction;
        cin >> y >> x >> direction;
        m[i] = {x-1, y-1, direction-1};
        graph[y-1][x-1].check.push_back(i);
    }

    int ans = -1;
    //Back of the vector must be the one on the top
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < k; j++){
            if(solve(j)){
                ans = i+1;
                break;
            }
        }

        if(ans != -1) break;
    }   

    cout << ans;

}
