#include <bits/stdc++.h>
using namespace std;

string A, B;
int B_num;
int ans = -1;
int visited[10];

void solve(int current_len, int num_len, string num){
    if(current_len == num_len){
        if(stoi(num) < B_num) ans = max(ans, stoi(num));
        return;
    }
    for(int i = 0; i < num_len; i++){
        if(visited[i] == 0 && !(num.length() == 0 && A[i] == '0')){
            visited[i] = 1;
            solve(current_len+1, num_len, num + A[i]);
            visited[i] = 0;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> A >> B;
    memset(visited, 0, sizeof(visited));
    B_num = stoi(B);
    
    solve(0, A.length(), "");
    cout << ans;
}
