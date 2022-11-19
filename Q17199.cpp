#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long


int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
  
    int n;
    cin >> n;
    vector<int> t[n+1];

    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        t[a].push_back(b);
    }

    int check[n+1];
    memset(check, 0, sizeof(check));

    bool visited[n+1];
    int ans = -1;
    for(int i = 1; i <= n; i++){
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        queue<int> q;
        q.push(i);

        while(!q.empty()){
            int current = q.front();
            q.pop();

            for(auto ch : t[current]){
                if(!visited[ch]){
                    visited[ch] = true;
                    q.push(ch);
                    check[ch]++;
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(check[i] == n-1){
            ans = i;
            break;
        }
    }

    cout << ans;

    

}
