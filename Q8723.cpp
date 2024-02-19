//Doing more codeforces rn

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long

bool right(int a, int b, int c){
    vector<int> nums = {a, b, c};
    sort(nums.begin(), nums.end());
    
    if(nums[0]*nums[0] + nums[1]*nums[1] == nums[2]*nums[2]){
        return true;
    }
    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);
 
    int a, b, c;
    cin >> a >> b >> c;

    if(a == b && b == c){
        cout << 2;
    }
    else if(right(a, b, c)){
        cout << 1;
    }
    else{
        cout << 0;
    }
    
}
