#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int floors, current_floor, wanted_floor;
    int up, down;
    
    cin >> floors >> current_floor >> wanted_floor >> up >> down;
    int visited[floors+1];
    memset(visited, -1, sizeof(visited));

    deque<int> dq;
    dq.push_back(current_floor);
    visited[current_floor] = 0;

    while(!dq.empty()){
        int temp = dq.front();
        dq.pop_front();

        if(up + temp <= floors && visited[up+temp] == -1){
            visited[up+temp] = visited[temp] + 1;
            dq.push_back(up+temp);
        }
        //Turns out ground floor is 1
        if(temp - down >= 1 && visited[temp-down] == -1){
            visited[temp-down] = visited[temp]  + 1;
            dq.push_back(temp-down);
        }
    }

    if(visited[wanted_floor] == -1) cout << "use the stairs";
    else cout << visited[wanted_floor];

}
