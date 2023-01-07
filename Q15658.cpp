//This should have took less effort...
#include <bits/stdc++.h>
using namespace std;

long long maximum = -1000000001;
long long minimum = 1000000001;
int num_count; 

void calc(int nums[], int add, int minus, int multi, int divide, int idx, long long current){
    if(idx == num_count){
        maximum = max(maximum, current);
        minimum = min(minimum, current);
        return;
    }
    if(add > 0) calc(nums, add-1, minus, multi, divide, idx+1, current+nums[idx]);
    if(minus > 0) calc(nums, add, minus-1, multi, divide, idx+1, current-nums[idx]);
    if(multi > 0) calc(nums, add, minus, multi-1, divide, idx+1, current*nums[idx]);
    if(divide > 0) calc(nums, add, minus, multi, divide-1, idx+1, current/nums[idx]);

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> num_count;

    int nums[num_count];
    for(int i = 0; i < num_count; i++){
        cin >> nums[i];
    }

    int operators[4];
    for(int j = 0; j < 4; j++){
        cin >> operators[j];
    }

    calc(nums, operators[0], operators[1], operators[2], operators[3], 1, nums[0]);
    cout << maximum << "\n" << minimum;

}


