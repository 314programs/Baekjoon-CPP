#include <bits/stdc++.h>
using namespace std;

int graph[101][101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int dimension;
    cin >> dimension;

    for(int y = 1; y <= dimension; y++){
        for(int x = 1; x <= dimension; x++){
            cin >> graph[y][x];
        }
    }
    
    //Floyd
    for(int k = 1; k <= dimension; k++){
        for(int i = 1; i <= dimension; i++){
            for(int j = 1; j <= dimension; j++){
                if(graph[i][j] == 0 && graph[i][k] == 1 && graph[k][j] == 1){
                    graph[i][j] = 1;
                }
            }
        }
    }

    for(int y = 1; y <= dimension; y++){
        for(int x = 1; x <= dimension; x++){
            cout << graph[y][x] << " ";
        }
        cout << "\n";
    }

}
