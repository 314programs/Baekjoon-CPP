#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int primes[1001];
    memset(primes, 0, 1001*4);
    primes[0] = 1;
    primes[1] = 1;
    
    for(int i = 2; i <= pow(1001, 0.5); i++){
        for(int j = i+i; j < 1001; j += i){
            primes[j] = 1;
        }
    }

    int testcase;
    int count = 0;
    cin >> testcase;

    while(testcase--){
        int num;
        cin >> num;
        if(primes[num] == 0){
            count += 1;
        }
    }

    cout << count;
    
}
