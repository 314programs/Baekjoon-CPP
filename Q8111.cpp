#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int tc;
    cin >> tc;
    
    //Maths is needed for this question...
    while(tc--){
        int n;
        cin >> n;
        
        //Vectors for storing path info
        //Will store by current number % n
        vector<int> from(n, -1);
        vector<int> how(n, -1);
        vector<int> dist(n, -1);
        queue<int> q;
        
        //Initial info
        q.push(1%n);
        dist[1%n] = 0;
        how[1%n] = 1;
        
        //BFS
        while(!q.empty()){
            int now = q.front();
            q.pop();

            for(int i = 0; i < 2; i++){
                //Add 1 or 0 to number
                int next = ((now*10)+i)%n;
                if(dist[next] == -1){
                    dist[next] = dist[now]+1;
                    from[next] = now;
                    how[next] = i;
                    q.push(next);
                }
            }
        }

        if(dist[0] == -1){
            cout << "BRAK\n";
        }
        else{
            //Use from and how to get the string
            string ans = "";
            for(int i = 0; i != -1; i = from[i]){
                ans += to_string(how[i]);
            }
            reverse(ans.begin(), ans.end());
            cout << ans << "\n";
        }
    }
}
