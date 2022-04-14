#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int primes[1000001];
    memset(primes, 0, 1000001*4);
    primes[0] = 1;
    primes[1] = 1;
    
    for(int i = 2; i <= pow(1000001, 0.5); i++){
        for(int j = i+i; j < 1000001; j += i){
            primes[j] = 1;
        }
    }

    int m, n;
    cin >> m >> n;

    for(int i = m; i <= n; i++){
        if(primes[i] == 0){
            cout << i << "\n";
        }
    }
    
}
