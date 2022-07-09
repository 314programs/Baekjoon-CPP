#include <bits/stdc++.h>
using namespace std;
long long dimension;

//Calculate how many numbers are smaller then the current number using division
long long calc(long long end){
    long long ans = 0;
    for(int i = 1; i <= dimension; i++){
        long long temp = (end/i);
        if(end%i == 0){
            temp -= 1;
        }
        ans += min(temp, dimension);
    }
    return ans;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> dimension;

    long long k;
    cin >> k;
    
    //Use binary search to find the specific number
    long long left = 1;
    long long right = dimension*dimension;
    long long ans = 0;
    while(left <= right){
        long long mid = (left+right)/2;
        if(calc(mid) >= k){
            right = mid-1;
        }
        else{
            ans = mid;
            left = mid + 1;
        }
    }
    cout << ans << " ";
}
