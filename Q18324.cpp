#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

//Kept getting it wrong cause there could be negative values...
//Set max(dist, 0) and all went well...
bool check(ll dist, ll speed, ll required){
    if(dist >= max(((speed-1+required)*(speed-required))/2, 0LL)){
        return true;
    }
    return false;
}

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    ll k, tc;
    cin >> k >> tc;
    while(tc--){
        ll n;
        cin >> n;
      
        //Use binary search to calculate maximum speed possible
        ll max_speed = n;
        ll left = 0, right = 100000;
        while(left <= right){
            ll mid = (left+right)/2;
            ll dist = k - (mid*(mid+1))/2;
            if(check(dist, mid, n)){
                max_speed = mid;
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        
        //Use maximum speed to calculate the time
        ll ans = max_speed+max(max_speed-n, 0LL);
        ll dist_left = (max_speed*(max_speed+1))/2;
        dist_left += max(((max_speed-1+n)*(max_speed-n))/2, 0LL);
        dist_left = k-dist_left;
        while(dist_left > 0){
            if(dist_left < max_speed){
                max_speed--;
            }
            else{
                dist_left -= max_speed;
                ans++;
            }
        }
        

        cout << ans << "\n";

    }

}
