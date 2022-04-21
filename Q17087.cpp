#include <bits/stdc++.h>
using namespace std;

int gdc(long long a, long long b){
    if(b == 0){
        return a;
    }
    else{
        return gdc(b, a%b);
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    long long brother_count, current_pos;
    cin >> brother_count >> current_pos;

    long long brothers[brother_count];
    for(int i = 0; i < brother_count; i++){
        long long temp;
        cin >> temp;
        //Calculate absolute distance
        brothers[i] = abs(temp-current_pos);
    }

    long long max_gcd = 1000000001;
    if(brother_count != 1){
        for(int i = 0; i < brother_count-1; i++){
            //Highest common factor between all numbers
            max_gcd = min(max_gcd, gcd(brothers[i], brothers[i+1]));
        }
    }
    else{
        max_gcd = brothers[0];
    }

    cout << max_gcd;
    
}
