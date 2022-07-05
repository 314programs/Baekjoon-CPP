#include <bits/stdc++.h>
using namespace std;

struct p{
    int num;
    int idx;
};

bool compare(p u, p v){
    return u.num < v.num;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    vector<p> A(n);
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        A[i] = {num, i};
    }

    stable_sort(A.begin(), A.end(), compare);
    int ans = 0;
    
    //Count index of item if item has been moved back
    for(int i = 0; i < n; i++){
        ans = max(ans, A[i].idx-i);
    }
    //Add one
    cout << ans + 1;
    
}
