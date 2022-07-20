#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int list_len, needed;
    cin >> list_len >> needed;
    vector<int> num_list(list_len);

    for(int i = 0; i < list_len; i++){
        cin >> num_list[i];
    }

    int left = 0, right = 0;
    long long s = num_list[0], ans = 0;

    while(left < list_len && right < list_len){
        if(s < needed){
            right++;
            s += num_list[right];
        }
        else if(s == needed){
            ans++;
            right++;
            s += num_list[right];
        }
        else if(s > needed){
            s -= num_list[left];
            left++;
        }
    }
    cout << ans;

}
