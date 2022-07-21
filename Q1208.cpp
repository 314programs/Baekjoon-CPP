#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int listlen, needed_num;
    cin >> listlen >> needed_num;

    vector<int> num_list(listlen);
    for(int i = 0; i < listlen; i++){
        cin >> num_list[i];
    }

    int front = listlen/2;
    int back = listlen - front;

    vector<int> front_nums(1 << front);
    for(int i = 0; i < (1 << front); i++){
        for(int j = 0; j < front; j++){
            if(i&(1 << j)) front_nums[i] += num_list[j];
        }
    }

    vector<int> back_nums(1 << back);
    for(int i = 0; i < (1 << back); i++){
        for(int j = 0; j < back; j++){
            if(i&(1 << j)) back_nums[i] += num_list[j + front];
        }
    }

    sort(front_nums.begin(), front_nums.end());
    sort(back_nums.begin(), back_nums.end());
    //Reverse one of the list to make programming easier
    reverse(back_nums.begin(), back_nums.end());

    int left = 0, right = 0;
    long long ans = 0;
    int l = (1<<front), r = (1<<back);
    
    //Meet in the middle
    while(left < l && right < r){
        long long current_num = front_nums[left] + back_nums[right];
        if(current_num > needed_num){
            right++;
        }
        else if(current_num < needed_num){
            left++;
        }
        else{
            long long f_count = 1;
            long long b_count = 1;
            left++;
            right++;

            while(left < l && front_nums[left] == front_nums[left-1]){
                f_count++;
                left++;
            }
            
            while(right < r && back_nums[right] == back_nums[right-1]){
                b_count++;
                right++;
            }
            ans += f_count * b_count;
        }
    }
    //0 will be added even if there is no zero in the list
    if(needed_num == 0) ans -= 1;
    cout << ans;

}
