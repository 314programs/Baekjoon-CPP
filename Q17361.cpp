#include <bits/stdc++.h>
using namespace std;

//Topological sort to get the order
vector<int> topo_sort(vector<vector<int>> outdegrees){
    int n = outdegrees.size();
    vector<int> indegrees(n);

    for(int i = 0; i < n; i++){
        for(auto ch: outdegrees[i]){
            indegrees[ch]++;
        }
    }

    queue<int> q;
    vector<int> order;
    for(int i = 0; i < n; i++){
        if(indegrees[i] == 0){
            q.push(i);
            order.push_back(i);
        }
    }

    while(!q.empty()){
        int current = q.front();
        q.pop();

        for(auto ch: outdegrees[current]){
            indegrees[ch]--;
            if(indegrees[ch] == 0){
                q.push(ch);
                order.push_back(ch);
            }
        }
    }

    return order;

}

//Function for finding K
bool go(int k, vector<int> &prev, vector<int> &order, vector<vector<int>> &outdegrees){
    int n = prev.size();
    vector<int> a(n);

    for(auto x: order){
        a[x] = 2000000000;
        //According to order, a[x] < a[y] since its reversed
        for(int y: outdegrees[x]){
            a[x] = min(a[x], a[y]-1);
        }
        //Before K, A[i] = prev[i] (i < K)
        if(x < k){
            if(prev[x] > a[x]) return false;
            a[x] = prev[x];
        }
        //Should not be 0 or below 0
        if(a[x] <= 0){
            return false;
        }
    }
    
    //If the conditions for K is true
    for(int i = 0; i < n; i++){
        if(a[i] > prev[i]) return true;
        if(a[i] < prev[i]) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    //Input
    int list_len, condition_cnt;
    cin >> list_len >> condition_cnt;
    
    vector<vector<int>> outdegrees(list_len);
    vector<vector<int>> outdegrees2(list_len);
    vector<int> prev(list_len);

    for(int i = 0; i < list_len; i++){
        cin >> prev[i];
    }

    for(int i = 0; i < condition_cnt; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        outdegrees[a].push_back(b);
        outdegrees2[b].push_back(a);
    }
    
    //Topological search
    vector<int> order;
    order = topo_sort(outdegrees);
    
    //Answer doesn't exist
    if(order.size() != list_len){
        cout << -1;
        return 0;
    }
    
    //A position called K in the list must exist
    //Where 0 < K <= n, A[i] = prev[i] (i < K), A[k] > prev[k]
    //Use binary search to find K
    int ans = 0;
    int left = 0;
    int right = list_len-1;
    //Reversed order for the binary search
    reverse(order.begin(), order.end());

    while(left <= right){
        int mid = (left+right)/2;
        if(go(mid, prev, order, outdegrees)){
            left = mid+1;
            ans = max(ans, mid);
        }
        else{
            right = mid-1;
        }
    }
    reverse(order.begin(), order.end());
    
    //Has similarlogic to go function
    vector<int> a(list_len);
    for(int x: order){
        a[x] = 1;
        //Use the graph with reversed directions
        //a[x] > a[y]
        for(int y : outdegrees2[x]){
            a[x] = max(a[x], a[y]+1);
        }
        //Before K
        if(x < ans){
            a[x] = prev[x];
        }
        //At K, get max value for a[k] to ensure that A[k] > prev[k]
        else if(x == ans){
            a[x] = max(a[x], prev[x]+1);
        }
    }

    for(auto ch: a){
        cout << ch << " ";
    }

}
