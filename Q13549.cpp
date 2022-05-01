#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int current_pos, brother_pos;
    cin >> current_pos >> brother_pos;

    deque<int> dq;
    int visited[100001];
    memset(visited, -1, sizeof(visited));

    visited[current_pos] = 0;
    dq.push_back(current_pos);

    while(!dq.empty()){
        int temp = dq.front();
        dq.pop_front();
        
        /*
        It is important that this if statement comes before others
        Else visited[temp*2] might not have the shortest distance, giving the wrong answer
        Or just change the if statement to this: if(temp * 2 <= 100000 && (visited[temp*2] == -1 || visited[temp*2] > visited[temp]))
        */
        
        if(temp * 2 <= 100000 && visited[temp*2] == -1){
            visited[temp*2] = visited[temp];
            dq.push_front(temp*2);
        }
        if(temp + 1 <= 100000 && visited[temp+1] == -1){
            visited[temp+1] = visited[temp] + 1;
            dq.push_back(temp+1);
        }
        if(temp - 1 >= 0 && visited[temp-1] == -1){
            visited[temp-1] = visited[temp] + 1;
            dq.push_back(temp-1);
        }

        if(visited[brother_pos] != -1){
            cout << visited[brother_pos];
            break;
        }

    }

}

