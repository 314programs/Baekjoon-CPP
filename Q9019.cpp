#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int testcase;
    cin >> testcase;

    int visited[10000];
    int parent[10000];
    char how[10000];

    for(int case_ = 0; case_ < testcase; case_ ++){
        memset(visited, -1, sizeof(visited));
        memset(parent, 0, sizeof(parent));
        memset(how, 0, sizeof(how));

        int current, wanted;
        cin >> current >> wanted;
        
        queue<int> q_;
        q_.push(current);
        visited[current] = 0;
        parent[current] = -1;

        while(!q_.empty()){
            int temp = q_.front();
            q_.pop();

            //D
            int d_ = (temp*2)%10000;
            if(visited[d_] == -1){
                visited[d_] = visited[temp] + 1;
                parent[d_] = temp;
                q_.push(d_);
                how[d_] = 'D';
            }

            //S
            int s_ = temp - 1;
            //0 can be given as a wanted number too...
            //So only if it goes under 0, it will convert to 9999
            if(s_ < 0) s_ = 9999;
            if(visited[s_] == -1){
                visited[s_] = visited[temp] + 1;
                parent[s_] = temp;
                q_.push(s_);
                how[s_] = 'S';
            }

            //L
            int l_ = (temp%1000)*10 + temp/1000;
            if(visited[l_] == -1){
                visited[l_] = visited[temp] + 1;
                parent[l_] = temp;
                q_.push(l_);
                how[l_] = 'L';
            }

            //R
            int r_ = temp/10 + ((temp%10)*1000);
            if(visited[r_] == -1){
                visited[r_] = visited[temp] + 1;
                parent[r_] = temp;
                q_.push(r_);
                how[r_] = 'R';
            }


        }

        string ans = "";
        while(true){
            if(parent[wanted] == -1) break;
            ans += how[wanted];
            wanted = parent[wanted];
        }
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }

}


 
