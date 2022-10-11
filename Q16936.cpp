#include <bits/stdc++.h>
using namespace std;

int list_len;
int visited[101];

int solve(int idx, vector<long long> & ans, vector<long long> & num_list){
    if(idx == list_len){
        for(auto ch: ans){
            cout << ch << " ";
        }
        cout << "\n";
        return 1;
    }
    for(int i = 0; i < list_len; i++){
        if(visited[i] == 0){
            //Accidently wrote num_list[idx-1] and hard time figuring out where it went wrong
            if(idx == 0 || (ans[idx-1] * 2) == num_list[i] || (ans[idx-1]%3 == 0 && ans[idx-1]/3 == num_list[i])){
                visited[i] = 1;
                ans[idx] = num_list[i];
                if(solve(idx+1, ans, num_list) == 1){
                    return 1;
                }
                visited[i] = 0;
            }
        }
    }
    return 0;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> list_len;

    vector<long long> num_list(list_len);
    vector<long long> ans(list_len);

    for(int i = 0; i < list_len; i++){
        cin >> num_list[i];
    }

    memset(visited, 0, sizeof(visited));
    solve(0, ans, num_list);

}
