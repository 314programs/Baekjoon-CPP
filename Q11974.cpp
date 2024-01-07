//Bored during chinese

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    ll n;
    cin >> n;

    vector<ll> s(n+1);
    s[0] = 0;
    for(int i = 1; i <= n; i++){
        int num;
        cin >> num;
        s[i] = s[i-1]+num;
    }

    int ans = 0;
    //We can approach the problem mathematically
    //We cna use remainders instead of a nested for loop to find all possible values
    //Since for the correct subarray, the remainder of 2 positions must be equal, we find the smallest and largest number for the remainder
    //Then see which one gives the maximum answer
  
    for(int i = 0; i < 7; i++){
        int start = -1, end = -1;
        for(int j = 0; j <= n; j++){
            if(s[j]%7 == i){
                start = j;
                break;
            }
        }
        for(int j = n; j >= 0; j--){
            if(s[j]%7 == i){
                end = j;
                break;
            }
        }
        ans = max(end-start, ans);
    }
    cout << ans;

}
