#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    long long pinaso = 1500000;
    long long mod = 1000000;
    long long num;
    cin >> num;
    num %= pinaso;

    long long prev = 0;
    long long current = 1;
    
    //When I tried using list, it gave me a segmentation fault
    for(int i = 2; i <= num; i++){
        long long temp = current;
        current = (prev+current)%mod;
        prev = temp;
    }
    cout << current;

}
