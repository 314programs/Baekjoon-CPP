#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

//Stores distance between points
int dist[1005][1005];

//Stores location of cases
//Number of current case, 0 = y, 1 = 0
int a[1005][1005];

//first police car pos, second police car pos
//position is displayed by number of case
//first case = (1,1), second case = (n,n)
int DP[1005][1005];

//Used for backtracking
//First car location, second car location = previous
int v[1005][1005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int m, n;
    cin >> m >> n;
    n += 2;

    //Setting initial positions of police cars
    a[1][0] = 1;
    a[1][1] = 1;
    a[2][0] = m;
    a[2][1] = m;

    for(int i = 3; i <= n; i++){
        cin >> a[i][0] >> a[i][1];
    }

    //Calculating all possible distances
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dist[i][j] = abs(a[i][0] - a[j][0]) + abs(a[i][1] - a[j][1]);
            dist[j][i] = dist[i][j];
            DP[i][j] = DP[j][i] = inf;
        }
    }

    //Set DP[1][2] to 0 because the police car are at their initial position
    DP[1][2] = 0;

    //For each cases...
    //i = current, j = prev (has to be smaller then current)
    for(int i = 3; i <= n; i++){
        for(int j = 1; j < i-1; j++){
            //v values are for backtracking...

            //i = first car position, j = second car position 
            //If first police car was at i-1, second one has to be at j
            if(DP[i-1][i] > DP[i-1][j] + dist[j][i]){
                //previous: i-1 = 1st, j = 2nd
                //From j to i on second car...
                DP[i-1][i] = DP[i-1][j] + dist[j][i];
                v[i-1][i] = j;
            }
            //If first police car is not at i-1(j), second one has to be at i-1
            //previous: j = 1st, i-1 = 2nd
            //From i-1 to i on second car...
            DP[j][i] = DP[j][i-1] + dist[i-1][i];
            v[j][i] = i-1;
            

            //i = second car position, j = first car position 
            //If second police car was at i-1, first one has to be at j
            if(DP[i][i-1] > DP[j][i-1] + dist[j][i]){
                //previous: j = 1st, i-1 = 2nd
                //From j to i on the first car...
                DP[i][i-1] = DP[j][i-1] + dist[j][i];
                v[i][i-1] = j;
            }
            //If second police car is not at i-1(j), first one has to be at i-1
            //previous: i-1 = 1st, j = 2nd
            //From i-1 to i on first car.
            DP[i][j] = DP[i-1][j] + dist[i-1][i]; 
            v[i][j] = i-1;

        }
    }

    int ans = inf;

    //First car, second car
    int x, y;

    //Initial values + ans for output
    for(int i = 1; i <= n; i++){
        if(DP[n][i] < ans){
            ans = DP[n][i];
            x = n;
            y = i;
        }
        if(DP[i][n] < ans){
            ans = DP[i][n];
            x = i;
            y = n;
        }
    }

    //if a car's position is bigger, it means it went first
    stack<int> s;
    for(int i = 0; i < n-2; i++){
        int prev = v[x][y];
        if(x > y){
            s.push(1);
            x = prev;
        }
        else{
            s.push(2);
            y = prev;
        }
    }

    //Print
    cout << ans << "\n";
    while(!s.empty()){
        cout << s.top() << "\n";
        s.pop();
    }
    

}
