#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int height, width;
    int graph[1000][1000];
    cin >> height >> width;

    int row_s[height];
    int column_s[width];
    
    memset(row_s, 0, sizeof(row_s));
    memset(column_s, 0, sizeof(column_s));

    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            cin >> graph[y][x];
        }
    }
    
    //Original
    long long total = 0;
    for(int y = 0; y < height-1; y++){
        for(int x = 0; x < width-1; x++){
            total += graph[y][x] + graph[y+1][x] + graph[y][x+1] + graph[y+1][x+1];
        }
    }
    
    //When list addition if performed... it takes a form of something like this
    /*
    1 2 ... 2 1
    2 4 ... 4 2
    . 4 ... 4 .
    2 4 ... 4 2
    1 2 ... 2 1
    */
    
    //We will use that to store value of each row and column
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            row_s[y] += 4 * graph[y][x];
        }
        row_s[y] -= 2*graph[y][0] + 2*graph[y][width-1];
        if(y == 0 || y == height-1) row_s[y] /= 2;
    }

    for(int x = 0; x < width; x++){
        for(int y = 0; y < height; y++){
            column_s[x] += 4 * graph[y][x];
        }
        column_s[x] -= 2*graph[0][x] + 2*graph[height-1][x];
        if(x == 0 || x == width-1) column_s[x] /= 2;
    }
  
    long long ans = total;
    //Since switching out inner columns and rows are useless, outer ones will be switched and compared
    for(int y = 1; y < height-1; y++){
        ans = max(ans, total + row_s[0] - (row_s[y]/2));
        ans = max(ans, total + row_s[height-1] - (row_s[y]/2));
    }

    for(int x = 1; x < width-1; x++){
        ans = max(ans, total + column_s[0] - (column_s[x]/2));
        ans = max(ans, total + column_s[width-1] - (column_s[x]/2));
    }

    cout << ans;

}
