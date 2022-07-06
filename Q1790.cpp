#include <bits/stdc++.h>
using namespace std;

long long calc(int n){
    long long length = 0;
    for(int start = 1, digit = 1; start <= n; digit++, start *= 10){
        int end = (start*10)-1;
        if(n < end){
            end = n;
        }
        length += (end - start + 1) * digit;
    }
    return length;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int N, k;
    cin >> N >> k;

    int left = 1, right = N;
    int ans = 0;

    if(calc(N) < k){
        cout << -1;
        return 0;
    }

    while(left <= right){
        int mid = (left+right)/2;
        long long mid_digit = calc(mid);

        if(mid_digit < k){
            left = mid + 1;
        }
        else{
            ans = mid;
            right = mid - 1;
        }
    }
    string s = to_string(ans);
    int len_ = calc(ans);
    cout << s[s.length()-1-(len_ - k)];
}
