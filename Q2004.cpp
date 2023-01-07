#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    long long n, m;
    long long five = 0, two = 0;
    cin >> n >> m;
  
    //Count number of 2s and 5s, add and subtract according to combination formula:
    //n!/r!(n-r)!
  
    for(long long i = 5; i <= n; i*=5){
        five += n/i;
    }
    for(long long i = 5; i <= n-m; i*=5){
        five -= (n-m)/i;
    }
    for(long long i = 5; i <= m; i*=5){
        five -= m/i;
    }

    for(long long i = 2; i <= n; i*=2){
        two += n/i;
    }
    for(long long i = 2; i <= n-m; i*=2){
        two -= (n-m)/i;
    }
    for(long long i = 2; i <= m; i*=2){
        two -= m/i;
    }
  
    //Number of two can be less then 5
    cout << min(five, two);
    
}
