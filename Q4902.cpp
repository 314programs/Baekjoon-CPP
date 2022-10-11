#include <bits/stdc++.h>
using namespace std;

int ans;
int record[401][801];
int graph[401][801];

void solve(int row, int left, int right, int total, int total_height){
    if(row < 1 || row > total_height) return;
    if(left < 1 || right > row*2 - 1) return;
    
    total += record[row][right] - record[row][left-1];

    ans = max(total, ans);
    //If x is even, triangle is reversed
    if(left%2 == 0){
        solve(row-1, left-2, right, total, total_height);
    }
    else{
        solve(row+1, left, right+2, total, total_height);
    }
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int case_ = 1;
    while(true){
        ans = -1001;
        memset(record, 0, sizeof(record));
        memset(graph, 0, sizeof(graph));

        int height;
        cin >> height;
        if(height == 0) break;
        
        //Record the sum of values
        for(int i = 1; i <= height; i++){
            for(int j = 1; j <= (i*2) - 1; j++){
                cin >> graph[i][j];
                record[i][j] = graph[i][j] + record[i][j-1];
            }
        }
        
        for(int i = 1; i <= height; i++){
            for(int j = 1; j <= (i*2) - 1; j++){
                solve(i, j, j, 0, height);
            }
        }
        cout << case_++ << ". " << ans << "\n";

    }
}
