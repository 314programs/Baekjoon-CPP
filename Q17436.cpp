#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    long long prime_cnt, limit;
    cin >> prime_cnt >> limit;
    long long ans = 0;

    vector<long long> primes(prime_cnt);
    for(int i = 0; i < prime_cnt; i++){
        cin >> primes[i];
    }
    
    //Find all combinations of all prime numbers
    for(int i = 1; i < (1 << prime_cnt); i++){
        int cnt = 0;
        long long multi = 1;
        for(int j = 0; j < prime_cnt; j++){
            if(i&(1<<j)){
                multi *= primes[j];
                cnt ++;
            }
        }
        
        //Find ones that is in union? with each other and removed them
        if(cnt%2 == 0){
            ans -= limit/multi;
        }
        //Add the ones removed from union
        else{
            ans += limit/multi;
        }

    }
    cout << ans;

}
