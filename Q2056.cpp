#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int building_cnt;
    cin >> building_cnt;

    int indegrees[building_cnt+1];
    int time[building_cnt+1];
    memset(indegrees, 0, sizeof(indegrees));
    vector<vector<int>> outdegrees(building_cnt+1, vector<int> (0));

    for(int i = 1; i <= building_cnt; i++){
        int need_cnt;
        cin >> time[i] >> need_cnt;
        indegrees[i] = need_cnt;
        for(int j = 0; j < need_cnt; j++){
            int temp;
            cin >> temp;
            outdegrees[temp].push_back(i);
        }
    }

    queue<int> q;
    int total_time[building_cnt+1];
    memset(total_time, 0, sizeof(total_time));
    for(int i = 1; i <= building_cnt; i++){
        if(indegrees[i] == 0){
            q.push(i);
            total_time[i] = time[i];
        }
    }

    
    while(!q.empty()){
        int current = q.front();
        q.pop();

        for(auto ch : outdegrees[current]){
            indegrees[ch] -= 1;
            //If the time calculated is more then time recorded, it will be the real time to finish all previous buildings
            //So change the value
            total_time[ch] = max(total_time[current] + time[ch], total_time[ch]);

            if(indegrees[ch] == 0){
                q.push(ch);
            }
        }
    }

    int ans = 0;
    //Get maximum total time, which is needed to finish the entire building
    for(int i = 1; i <= building_cnt; i++){
        ans = max(ans, total_time[i]);
    }
    cout << ans;

}
