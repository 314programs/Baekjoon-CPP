#include <bits/stdc++.h>
using namespace std;

bool sieve[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    memset(sieve, true, sizeof(sieve));
    vector<long long> square;
    long long min_val, max_val;
    cin >> min_val >> max_val;

    for(long long i = 2; i*i <= max_val; i++){
        //Get starting index
        long long start = i*i-min_val%(i*i);
        if(start == i*i){
            start = 0;
        }
        //Sieve
        for(long long j = start; j <= max_val - min_val; j += i*i){
            sieve[j] = false;
        }
    }

    long long ans = 0;
    //Find values still true
    for(long long i = 0; i <= max_val - min_val; i++){
        if(sieve[i]) ans++;
    }
    cout << ans;
}
