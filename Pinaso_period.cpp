#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    long long mod = 1000000;
    long long prev = 0;
    long long current = 1;
    long long pinaso = 0;

    for(long long i = 0; i < mod*mod; i++){
        long long temp = 0;
        temp = current;
        current = (current + prev)%mod;
        prev = temp;

        if(prev == 0 && current == 1){
            pinaso = i+1;
        }
    }
    cout << pinaso;

}
