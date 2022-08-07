//Back to DP!
#include <bits/stdc++.h>
using namespace std;

int graph[1000][1000];
int DP[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    memset(DP, 0, sizeof(DP));
    int height, width;
    cin >> height >> width;

    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            cin >> graph[y][x];
        }
    }

    for(int y = 1; y <= height; y++){
        for(int x = 1; x <= width; x++){
            //DP[y-1][x-1] is not needed as other 2 paths maximise the candy... but just decided to put it in
            DP[y][x] = max(max(DP[y][x-1], DP[y-1][x]), DP[y-1][x-1]) + graph[y-1][x-1]; 
        }
    }

    cout << DP[height][width];

}
