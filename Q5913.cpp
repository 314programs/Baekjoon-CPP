//Small enough for backtracking

#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

struct point{
    int x, y;
};

int ans = 0;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

//Make this for easier if statements
bool check(int ux, int uy){
    if(ux >= 0 && ux < 5 && uy >= 0 && uy < 5) return true;
    return false;
}

void solve(vector<vector<int>> a, int end, point s, point e, int it){
    if(it > end) return;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            int s_nx = s.x + dx[i];
            int s_ny = s.y + dy[i];
            int e_nx = e.x + dx[j];
            int e_ny = e.y + dy[j];

            if(check(s_nx, s_ny) && check(e_nx, e_ny) && a[s_ny][s_nx] == 0 && a[e_ny][e_nx] == 0){
                if(s_nx == e_nx && s_ny == e_ny && it == end-1){
                    ans++;
                    return;
                }
                else if(!(s_nx == e_nx && s_ny == e_ny)){
                    vector<vector<int>> new_a = a;
                    new_a[s_ny][s_nx] = it+1;
                    new_a[e_ny][e_nx] = it+1;
                    solve(new_a, end, {s_nx, s_ny}, {e_nx, e_ny}, it+1);
                }
            }
        }
    }
}


int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<vector<int>> a(5, vector<int>(5, 0));

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        a[x-1][y-1] = -1;
    }
    a[0][0] = 1;
    a[4][4] = 1;
    solve(a, (25-n-1)/2, {0,0}, {4,4}, 0);
    cout << ans;

}
