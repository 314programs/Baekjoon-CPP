#include <bits/stdc++.h>
using namespace std;

long long const MAX = 100000;
bool sieve[MAX+1];
vector<long long> squares;

long long count_nn(long long idx, long long end, long long multi){
    //All combinations using each of the numbers
    //Using backtracking instead of bitmasking since we can stop when the square number gets too big
    long long ans = 0;
    if(idx >= squares.size()) return 0;
    if(squares[idx]*multi > end) return 0;

    ans += end/(multi*squares[idx]);
    ans += count_nn(idx+1, end, multi);
    ans -= count_nn(idx+1, end, multi*squares[idx]);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    memset(sieve, false, sizeof(sieve));
    //Make all square numbers first
    for(long long i = 2; i <= MAX; i++){
        if(sieve[i]) continue;
        squares.push_back(i*i);
        for(long long j = i+i; j <= MAX; j += i){
            sieve[j] = true;
        }
    }

    long long k;
    cin >> k;
    
    //Binary search to find the kth number
    long long left = 0; 
    long long right = 2147483647;
    long long ans = -1;
    
    while(left <= right){
        long long middle = (left+right)/2;
        //The functions finds how many numbers are divisible by square numbers
        //So to find numbers that are not divisible, subtract the function value from original number
        long long cnt = middle - count_nn(0, middle, 1);

        if(cnt >= k){
            ans = middle;
            right = middle - 1;
        }
        else{
            left = middle + 1;
        }

    }

    cout << ans;

}
