#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int nodes;
    vector<int> graph[100000];
    int parent[100000];
    int visited[100000];
    int order[100000];

    cin >> nodes; 

    for(int i = 0; i < nodes-1; i++){
        int a,b;
        cin >> a >> b;
        //Remember that there was a subtraction to make things easier
        a -= 1; b -= 1;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 0; i < nodes; i++){
        cin >> order[i];
        order[i] -= 1;
    }
    
    memset(visited, 0, sizeof(visited));

    int ans = 1;
    queue<int> q_;
    
    //Start has to be 0
    q_.push(0);
    visited[0] = 1;
    parent[0] = -1;

    int size = 1;

    for(int i = 0; i < nodes; i++){
        if(q_.empty()){
            ans = 0;
            break;
        }

        int temp = q_.front(); 
        q_.pop();

        int cnt_ = 0;
        
        //Marking parent and visited
        for(int ch: graph[temp]){
            if(visited[ch] == 0){
                parent[ch] = temp;
                cnt_ += 1;
            }

        }

        for(int j = 0; j < cnt_; j++){
            //Checking if values are within the index and has a proper parent
            if(size + j < nodes && parent[order[size + j]] == temp){
                q_.push(order[size + j]);
                visited[order[size + j]] = 1;
            }
            else{
                ans = 0;
                break;
            }
        }

        size += cnt_;

    }

    cout << ans;
    
}

