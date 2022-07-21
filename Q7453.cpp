#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> A(n), B(n), C(n), D(n);
    for(int i = 0; i < n; i++){
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    
    //A[a] + B[b] = -(C[c] + D[d])
    //Make all combinations here
    vector<int> front, back;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            front.push_back(A[i] + B[j]);
            back.push_back(C[i] + D[j]);
        }
    }
    
    //Sort for getting lower and upper bound
    sort(back.begin(), back.end());

    long long ans = 0;
    for(auto ch: front){
        //Locate lower and upper bound for a negative of current number
        auto p = equal_range(back.begin(), back.end(), -ch);
        //Calculate how many -ch is inside the list
        ans += p.second - p.first;
    }

    cout << ans;
}
