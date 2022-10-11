#include <bits/stdc++.h>
using namespace std;

struct bridge{
    int to, max_weight, bridge_num;
};

int island_num, bridge_num;
map<int, vector<bridge>> bridges;

//Test the weight by BFS, seeing if it can cross bridges properly
bool BFS(int start, int end, int weight){
    int visited[100001];
    memset(visited, 0, sizeof(visited));

    deque<int> dq;
    dq.push_back(start);
    visited[start] = 1;

    while(!dq.empty()){
        int temp_location = dq.front();
        dq.pop_front();
        
        if(temp_location == end) return true;

        for(auto ch: bridges[temp_location]){
            int next_location = ch.to;
            if(visited[next_location] == 0 && ch.max_weight >= weight){
                visited[next_location] = 1;
                dq.push_back(next_location);
            }
        }
    }
    return false;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> island_num >> bridge_num;

    for(int i = 1; i <= island_num; i++){
        bridges[i] = {};
    }
    
    int temp = 1;
    int min_ = 1000000001, max_ = 0;
    for(int i = 0; i < bridge_num; i++){
        int A,B,C;
        cin >> A >> B >> C;
        bridges[A].push_back((bridge){B, C, temp++});
        bridges[B].push_back((bridge){A, C, temp++});
        min_ = min(min_, C);
        max_ = max(max_, C);
    }

    int start, end;
    cin >> start >> end;
    int ans = 0;
  
    //Use binary search to determine maximum weight 
    while(min_ <= max_){
        int mid = (min_ + max_) / 2;
        bool temp = BFS(start, end, mid);
        if(temp == true){
            ans = mid;
            min_ = mid + 1;
        }
        else{
            max_ = mid - 1;
        }
    }
    cout << ans;

}
