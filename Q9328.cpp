#include <bits/stdc++.h>
using namespace std;

char graph[102][102];
bool visited[102][102];
bool key[26];

struct node{
    int x, y;
};

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int tc;
    cin >> tc;
    while(tc--){
        memset(graph, '.', sizeof(graph));
        memset(key, false, sizeof(key));
        memset(visited, false, sizeof(visited));

        int height, width;
        cin >> height >> width;
        int ans = 0;

        for(int y = 1; y <= height; y++){
            string s;
            cin >> s;
            for(int x = 1; x <= width; x++){
                graph[y][x] = s[x-1];
            }
        }

        string k;
        cin >> k;
        if(k != "0"){
            for(auto ch: k){
                key[ch - 'a'] = true;
            }
        }

        queue<node> q;
        //Will go in when key is aquired
        queue<node> kq[26];
        q.push({0, 0});

        while(!q.empty()){
            node current = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int nx = current.x + dx[i];
                int ny = current.y + dy[i];
                if(nx >= 0 && nx < width+2 && ny >= 0 && ny < height+2 && visited[ny][nx] == false && graph[ny][nx] != '*'){
                    //Locked door
                    if(graph[ny][nx] >= 'A' && graph[ny][nx] <= 'Z'){
                        if(key[graph[ny][nx] - 'A'] == false){
                            kq[graph[ny][nx] - 'A'].push({nx, ny});
                        }
                        else{
                            q.push({nx, ny});
                        }
                        visited[ny][nx] = true;
                    }
                    //Key
                    else if(graph[ny][nx] >= 'a' && graph[ny][nx] <= 'z'){
                        key[graph[ny][nx] - 'a'] = true;
                        while(!kq[graph[ny][nx] - 'a'].empty()){
                            q.push(kq[graph[ny][nx] - 'a'].front());
                            kq[graph[ny][nx] - 'a'].pop();
                        }
                        visited[ny][nx] = true;
                        q.push({nx, ny});
                    }
                    //Other
                    else{
                        if(graph[ny][nx] == '$') ans++;
                        visited[ny][nx] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }

        cout << ans << "\n";
    }

}
