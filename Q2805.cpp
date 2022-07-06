#include <bits/stdc++.h>
using namespace std;

long long calc(long long cut_line, vector<long long> & trees){
    long long ans = 0;
    for(long long ch: trees){
        ans += max((ch-cut_line), (long long)0);
    }
    return ans;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int tree_num;
    long long needed_len;

    cin >> tree_num >> needed_len;
    vector<long long> trees(tree_num);
    long long max_ = 0;

    for(int i = 0; i < tree_num; i++){
        cin >> trees[i];
        max_ = max(max_, trees[i]);
    }

    long long left = 0, right = max_;
    long long ans = 0;

    while(left <= right){
        long long mid = (left+right)/2;
        long long len_ = calc(mid, trees);
        
        if(len_ >= needed_len){
            left = mid+1;
            ans = mid;
        }
        else{
            right = mid-1;
        }
    }
    cout << ans;
}
