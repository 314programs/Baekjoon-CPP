#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

ll can(int n, vector<ll> &a){
    if(n == 1) return 0;
    ll ans = 0;
    
    //If can be solved, traversing twice is the maximum amount, else question cannot be solved
    //Left to right, right to left(done by reversing)
    //In the end all hungers levels will be equal or below the minimum number as numbers cannot be increased in this loop
    for(int i = 0; i < 2; i++){
        for(int j = 1; j < n-1; j++){
            //Want to make a[j] = [j-1]
            if(a[j] > a[j-1]){
                int diff = a[j]-a[j-1];
                ans += diff*2;
                a[j+1] -= diff;
                a[j] = a[j-1];
            }
        }
        //Must be in descending order to solve since hunger values cannot increase further
        if(a[n-1] > a[n-2]) return -1;
        //Reverse to repeat instead of right to left
        reverse(a.begin(), a.end());
    }
    
    //Since its reversed, we have to check if the last element is negative or not using a[0]
    if(a[0] < 0){
        return -1;
    }
    else{
        return ans;
    }

}

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;

        vector<ll> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        cout << can(n, a) << "\n";

    }


}
