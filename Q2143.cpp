#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int needed_num;
    int front_len, back_len;
    cin >> needed_num;
    cin >> front_len;

    vector<int> front(front_len);
    for(int i = 0; i < front_len; i++){
        cin >> front[i];
    }

    cin >> back_len;
    vector<int> back(back_len);
    for(int i = 0; i < back_len; i++){
        cin >> back[i];
    }
    
    vector<int> front_sum;
    for(int i = 0; i < front_len; i++){
        int s = 0;
        for(int j = i; j < front_len; j++){
            s += front[j];
            front_sum.push_back(s);
        }
    }

    vector<int> back_sum;
    for(int i = 0; i < back_len; i++){
        int s = 0;
        for(int j = i; j < back_len; j++){
            s += back[j];
            back_sum.push_back(s);
        }
    }

    sort(front_sum.begin(), front_sum.end());
    sort(back_sum.begin(), back_sum.end());
    reverse(back_sum.begin(), back_sum.end());

    int left = 0, right = 0;
    int l = front_sum.size(), r = back_sum.size();
    long long ans = 0;

    while(left < l && right < r){
        int current_num = front_sum[left] + back_sum[right];
        if(current_num > needed_num){
            right++;
        }
        else if(current_num < needed_num){
            left++;
        }
        else{
            long long r_count = 1;
            long long l_count = 1;
            left++;
            right++;

            while(left < l && front_sum[left] == front_sum[left-1]){
                left++;
                l_count++;
            }

            while(right < r && back_sum[right] == back_sum[right-1]){
                right++;
                r_count++;
            }
            ans += r_count * l_count;
        }
    }
    cout << ans;
}
