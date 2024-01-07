#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int n;
    cin >> n;
    //Make prime first
    vector<int> prime_check(n+1);

    if(n == 1){
        cout << 0;
        return 0;
    }

    for(int i = 2; i*i < n+1; i++){
        if(prime_check[i] == 0){
            for(int j = i + i; j < n+1; j += i){
                prime_check[j] = 1;
            }
        }
    }

    vector<int> prime;
    for(int i = 2; i < n+1; i++){
        if(prime_check[i] == 0) prime.push_back(i);
    }

    int len_ = prime.size();
    int left = 0, right = 0;
    int ans = 0, s = prime[0];
    
    //Two pointer
    while(left < len_ && right < len_){
        if(s < n){
            right++;
            s += prime[right];
        }
        else if(s == n){
            right++;
            s += prime[right];
            ans++;
        }
        else if(s > n){
            s -= prime[left];
            left++;
        }
    }
    cout << ans;

}
