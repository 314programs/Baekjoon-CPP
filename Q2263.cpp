#include <bits/stdc++.h>
using namespace std;

int in_order[100000];
int post_order[100000];
int position[100001];

void solve(int in_start, int in_end, int post_start, int post_end){
    if(in_start > in_end || post_start > post_end) return;

    int root = post_order[post_end];
    int root_pos = position[root];
    cout << root << " ";

    int left_size = root_pos - in_start;
    //Always assumed post_start = 0, which is not true
    solve(in_start, root_pos - 1, post_start, post_start + left_size - 1);
    solve(root_pos + 1, in_end, post_start + left_size, post_end-1);

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int len_;
    cin >> len_;

    for(int i = 0; i < len_; i++){
        cin >> in_order[i];
        position[in_order[i]] = i;
    }
    for(int i = 0; i < len_; i++){
        cin >> post_order[i];
    }

    solve(0, len_ - 1, 0, len_ - 1);
}
