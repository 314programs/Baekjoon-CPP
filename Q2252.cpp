//Topological sort... forgot this existed for a while but got a hang of it quickly
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int student_cnt, compare_cnt;
    cin >> student_cnt >> compare_cnt;
    
    //Make indegrees(count) and outdegrees(list)
    int indegrees[student_cnt+1];
    memset(indegrees, 0, sizeof(indegrees));
    vector<vector<int>> outdegrees(student_cnt+1, vector<int> (0));

    for(int i = 0; i < compare_cnt; i++){
        int from, to;
        cin >> from >> to;
        indegrees[to]++;
        outdegrees[from].push_back(to);
    }
    
    queue<int> q;
    //elements with no indegrees goes first
    for(int i = 1; i <= student_cnt; i++){
        if(indegrees[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int current = q.front();
        cout << current << " ";
        q.pop();
        
        //Reduce indegrees by using the outdegrees list
        for(auto ch : outdegrees[current]){
            indegrees[ch] -= 1;
            if(indegrees[ch] == 0){
                q.push(ch);
            }
        }

    }

}
