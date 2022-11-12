//As always in ad hoc... why does this work???
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

vector<int> connection[1000];
 
int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    int visited[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    //Going to use BFS
    connection[0].push_back(1);
    for(int i = 1; i < n-1; i++){
        if(a[i+1]-a[i] < a[i]-a[i-1]){
            connection[i].push_back(i+1);
        }
        else if(a[i+1]-a[i] >= a[i]-a[i-1]){
            connection[i].push_back(i-1);
        }
    }
    if(n > 1){
        connection[n-1].push_back(n-2);
    }
    
    //Which cow passes the ball to most cows
    int ans = 0;
    vector<pair<int, int>> order(n);
    for(int i = 0; i < n; i++){
        memset(visited, false, sizeof(visited));
        int cnt = 0;
        queue<int> q;
        q.push(i);
        visited[i] = true;

        while(!q.empty()){
            cnt++;
            int current = q.front();
            q.pop();

            for(auto ch: connection[current]){
                if(visited[ch] == false){
                    visited[ch] = true;
                    q.push(ch);
                }
            }
        }
        order[i] = make_pair(cnt, i);
    }
    
    //The cows that pass most ball to other cows will pass first
    sort(order.begin(), order.end());
    reverse(order.begin(), order.end());
    memset(visited, false, sizeof(visited));
    for(auto o: order){
        if(!visited[o.second]){
            ans++;
            queue<int> q;
            q.push(o.second);
            visited[o.second] = true;

            while(!q.empty()){
                int current = q.front();
                q.pop();

                for(auto ch: connection[current]){
                    if(visited[ch] == false){
                        visited[ch] = true;
                        q.push(ch);
                    }
                }
            }
        }
    }

    cout << ans;

}
