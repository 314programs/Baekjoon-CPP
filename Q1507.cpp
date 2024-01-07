#include <bits/stdc++.h>
using namespace std;

int graph[20][20];
bool unused[20][20];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int dimension;
    cin >> dimension;

    memset(unused, false, sizeof(unused));
    for(int y = 0; y < dimension; y++){
        for(int x = 0; x < dimension; x++){
            cin >> graph[y][x];
        }
    }
    
    //Floyd warshall with extras
    for(int k = 0; k < dimension; k++){
        for(int i = 0; i < dimension; i++){
            //Skip if at least 2 of them are the same... we already have the route for them and we don't want them to be marked as unused...
            //They will get skipped since graph[i][i] == 0 and the route is added to it
            if(k == i) continue;
            for(int j = 0; j < dimension; j++){
                if(k == j) continue;
                if(i == j) continue;
                
                //When its not the shortest route
                if(graph[i][j] > graph[i][k] + graph[k][j]){
                    cout << -1;
                    return 0;
                }
                
                //When other routes can be used to replace this one
                if(graph[i][j] == graph[i][k] + graph[k][j]){
                    unused[i][j] = true;
                }
            }
        }
    }

    int ans = 0;
    for(int y = 0; y < dimension; y++){
        for(int x = 0; x < dimension; x++){
            if(!unused[y][x]) ans += graph[y][x];
        }
    }
    //Divide it in half since it repeats twice
    ans /= 2;
    cout << ans;

}
