//Gold 5 but confusing
#include <bits/stdc++.h>
using namespace std;

int cap[3];
//All possibilities of movement
int from[6] = {0, 0, 1, 1, 2, 2};
int to[6] = {1, 2, 0, 2, 1, 0};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int ans[201];
    //Only A, B needed as C can be calculated from its sum
    int visited[201][201];
    
    //Instead of A, B, C use a list for convinience
    cin >> cap[0] >> cap[1] >> cap[2];

    deque<pair<int, int>> dq;
    dq.push_back(make_pair(0, 0));
    ans[cap[2]] = 1;
    visited[0][0] = 1;

    while(!dq.empty()){
        auto temp = dq.front();
        int cur[3] = {temp.first, temp.second, cap[2] - temp.first - temp.second};
        dq.pop_front();

        for(int i = 0; i < 6; i++){
            int next[3] = {cur[0], cur[1], cur[2]};
            //Adding water
            next[to[i]] += next[from[i]];
            next[from[i]] = 0;
            
            //Overflowing case
            if(next[to[i]] > cap[to[i]]){
                next[from[i]] = next[to[i]] - cap[to[i]];
                next[to[i]] = cap[to[i]];
            }
            
            //If not visited yet
            if(visited[next[0]][next[1]] == 0){
                visited[next[0]][next[1]] = 1;
                dq.push_back(make_pair(next[0], next[1]));
                if(next[0] == 0){
                    ans[next[2]] = 1;
                }
            }
        }
    }


    for(int i = 0; i <= cap[2]; i++){
        if(ans[i] == 1) cout << i << " ";
    }

}
