#include <bits/stdc++.h>
using namespace std;

int ans = -1;
void backtrack(long long start, long long end, int movement){
    if(start > end){
        return;
    }
    if(start == end){
        if(ans == -1 || ans > movement){
            ans = movement + 1;
        }
    }

    backtrack(start*2, end, movement+1);
    backtrack((start*10)+1, end, movement+1);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    long long start, end;
    cin >> start >> end;

    backtrack(start, end, 0);
    cout << ans;
}
