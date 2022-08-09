//I hate DP
#include <bits/stdc++.h>
using namespace std;

long long DP[100][100];
int graph[100][100];
int dimension;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    memset(DP, 0, sizeof(DP));
    cin >> dimension;

    for(int y = 0; y < dimension; y++){
        for(int x = 0; x < dimension; x++){
            cin >> graph[y][x];
        }
    }

    DP[0][0] = 1;
    for(int y = 0; y < dimension; y++){
        for(int x = 0; x < dimension; x++){
            //Go to next square if possible
            if(y + graph[y][x] < dimension && graph[y][x] > 0){
                DP[y + graph[y][x]][x] += DP[y][x];
            }
            if(x + graph[y][x] < dimension && graph[y][x] > 0){
                DP[y][x + graph[y][x]] += DP[y][x];
            }
        }
    }

    cout << DP[dimension-1][dimension-1];
}
