//Chessboard is back...

#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long
 
int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int height, width, k;
    cin >> height >> width >> k;
    int board[height][width];

    //W: 1, B: 0
    for(int i = 0; i < height; i++){
        string s;
        cin >> s;
        for(int j = 0; j < width; j++){
            board[i][j] = (s[j] == 'W');
        }
    }

    int black_first[height+1][width+1];
    int white_first[height+1][width+1];
    memset(black_first, 0, sizeof(black_first));
    memset(white_first, 0, sizeof(white_first));

    for(int i = 1; i <= height; i++){
        for(int j = 1; j <= width; j++){ 
            black_first[i][j] = black_first[i][j-1] + black_first[i-1][j] - black_first[i-1][j-1];
            white_first[i][j] = white_first[i][j-1] + white_first[i-1][j] - white_first[i-1][j-1];

            
            //If black
            if(board[i-1][j-1] == 0){
                if((i%2 == 1 && j%2 == 0) || (i%2 == 0 && j%2 == 1)) black_first[i][j]++;
                if((i%2 == 1 && j%2 == 1) || (i%2 == 0 && j%2 == 0)) white_first[i][j]++;
            }
            else{
                if((i%2 == 1 && j%2 == 1) || (i%2 == 0 && j%2 == 0)) black_first[i][j]++;
                if((i%2 == 1 && j%2 == 0) || (i%2 == 0 && j%2 == 1)) white_first[i][j]++;
            }
        }
    }


    int ans = 1e9;
    for(int i = 0; i <= height-k; i++){
        for(int j = 0; j <= width-k; j++){
            ans = min(ans, black_first[i+k][j+k] - black_first[i][j+k] - black_first[i+k][j] + black_first[i][j]);
            ans = min(ans, white_first[i+k][j+k] - white_first[i][j+k] - white_first[i+k][j] + white_first[i][j]);
        }
    }
    cout << ans;


}
