#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int sieve[1000001];
    vector<int> primes;

    memset(sieve, 0, sizeof(sieve));
    sieve[0] = 1;
    sieve[1] = 1;

    for(int i = 2; i <= 1000000; i++){
        if(sieve[i] == 0){
            primes.push_back(i);
            for(int j = i + i; j <= 1000000; j += i){
                sieve[j] = 1;
            }
        }
    }
}
