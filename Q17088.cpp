#include <bits/stdc++.h>
using namespace std;

int ans = 1000000;
//+1, 0, -1
//Marks all 3 cases
int mark[100000];

void solve(int idx, int list_len, vector<int> & num_list, int total_, int prev){
    if(idx == list_len+1){
        ans = min(ans, total_);
        return;
    }
    //Because current idx is not marked, extra -1 has to be added
    if(idx == 2){
        prev = (num_list[idx-2]+mark[idx-2]) - (num_list[idx-1]+mark[idx-1]);
    }
    //Return if value is not valid
    if(prev != -(1e+9) - 1 && prev != (num_list[idx-2]+mark[idx-2]) - (num_list[idx-1]+mark[idx-1])){
        return;
    }

    for(int i = -1; i <= 1; i++){
        //Mark for each case and proceed
        mark[idx] = i;
        solve(idx+1, list_len, num_list, total_ + abs(i), prev);
    }

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int list_len;
    cin >> list_len;

    vector<int> num_list(list_len);
    for(int i = 0; i < list_len; i++){
        cin >> num_list[i];
    }

    solve(0, list_len, num_list, 0, -(1e+9) - 1);
    //Ans not found
    if(ans == 1000000){
        cout << -1;
    }
    else{
        cout << ans;
    }
}
