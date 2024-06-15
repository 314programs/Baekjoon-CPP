#include <bits/stdc++.h>
using namespace std;

int visited[2][100001];
struct node{
    int line, y;
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<string> a(2);
    cin >> a[0] >> a[1];
    
    memset(visited, -1, sizeof(visited));
    queue<node> q;
    
    //I got it correct except the starting space...
    //How did I miss it
    q.push({0, 0});
    visited[0][0] = 0;

    int dx[3] = {0,0,1};
    int dy[3] = {1,-1,k};
    int ans = 0;

    while(!q.empty()){
        node current = q.front();
        q.pop();

        for(int j = 0; j < 3; j++){
            int x;
            if(dx[j] == 0) x = current.line;
            else if(dx[j] == 1){
                if(current.line == 0) x = 1;
                else x = 0;
            }
            int y = current.y + dy[j];
            if(y >= n){
                ans = 1;
                break;
            }
            if(y >= 0 && y < n && visited[x][y] == -1 && a[x][y] == '1' && visited[current.line][current.y] + 1 <= y){
                visited[x][y] = visited[current.line][current.y] + 1;
                q.push({x, y});
            }
        }
        if(ans == 1) break;
    }
    cout << ans;
}
