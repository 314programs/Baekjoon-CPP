#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int primes[1000001];
    int actual_prime[100000];
    int idx = 0;
    memset(primes, 0, 1000001*4);
    primes[0] = 1;
    primes[1] = 1;
    
    for(int i = 2; i <= 1000001; i++){
        if(primes[i] == 0){
            actual_prime[idx++] = i;
            for(int j = i+i; j < 1000001; j += i){
                primes[j] = 1;
            }
        }
    }

    while(true){
        int num;
        cin >> num;
        if(num == 0){
            break;
        }
        for(int i = 0; i < 100000; i++){
            if(primes[num-actual_prime[i]] == 0){
                cout << num << " = " << actual_prime[i] << " + " << num-actual_prime[i] << "\n";
                break;
            } 
        }
    }
    
}
