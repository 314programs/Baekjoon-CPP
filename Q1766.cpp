#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int student_cnt, compare_cnt;
    cin >> student_cnt >> compare_cnt;

    int indegrees[student_cnt+1];
    memset(indegrees, 0, sizeof(indegrees));
    vector<vector<int>> outdegrees(student_cnt+1, vector<int> (0));

    for(int i = 0; i < compare_cnt; i++){
        int from, to;
        cin >> from >> to;
        indegrees[to]++;
        outdegrees[from].push_back(to);
    }
    
    //Instead of queue, use priority_queue to make a min_heap since we need to solve easy questions first
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 1; i <= student_cnt; i++){
        if(indegrees[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int current = q.top();
        cout << current << " ";
        q.pop();

        for(auto ch : outdegrees[current]){
            indegrees[ch] -= 1;
            if(indegrees[ch] == 0){
                q.push(ch);
            }
        }

    }

}
