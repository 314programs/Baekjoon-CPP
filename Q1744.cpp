#include <bits/stdc++.h>
using namespace std;

bool compare(int u, int v){
    //Positive, negative, 0
    if(u < 0 && v < 0) return u < v;
    else if(u == 0) return false;
    else if(v == 0) return true;
    return u > v;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int num_count;
    cin >> num_count;
    vector<int> nums;

    for(int i = 0; i < num_count; i++){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    sort(nums.begin(), nums.end(), compare);
    int ans = 0;


    for(int i = 0; i < size(nums); i++){
        //If tying them together makes a higher number
        if(i + 1 < size(nums) && nums[i] * nums[i+1] > nums[i] + nums[i+1]){
            ans += nums[i] * nums[i+1];
            i++;
        }
        //If just adding makes a higher number
        else{
            ans += nums[i];
        }
    }

    cout << ans;

}
