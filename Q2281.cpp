#include <bits/stdc++.h>
using namespace std;

int names[1000];
int name_cnt, width;
//Which name, which line index
int DP[1001][1001];

int solve(int name_idx, int line_idx){
    if(name_idx == name_cnt){
        return 0;
    }
    
    //Memoization to save time
    int &ans = DP[name_idx][line_idx];
    if(ans != -1) return ans;
    ans = 1e9;

    //Add name to current line
    if(line_idx + names[name_idx] <= width){
        ans = min(solve(name_idx + 1, line_idx + names[name_idx]+1), ans);
    }

    //Move to next line
    if(line_idx != 0){
        //+1 to remove the extra spacing
        int multi = width -line_idx + 1;
        ans = min(solve(name_idx + 1, names[name_idx]+1) + multi * multi, ans);
    }
    return ans;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    memset(DP, -1, sizeof(DP));
    cin >> name_cnt >> width;
    for(int i = 0; i < name_cnt; i++){
        cin >> names[i];
    }

    cout << solve(0, 0);

}
