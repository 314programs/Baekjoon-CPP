#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
#define int long long

//C^n == C^(n/2) * C^(n/2) if n is even
//C^n == C^(n/2) * C^(n/2) * C if n is odd
int mod_pow(int num, int pow, int mod){
    if(pow == 0) return 1;
    int ans = mod_pow(num, pow/2, mod);

    if(pow%2 == 0){
        return (ans*ans)%mod;
    }
    else{
        return (ans*ans*num)%mod;
    }
}

int32_t main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cout << mod_pow(3, 17, 29);

}
