//Kept using int and wondered why I got it wrong...
#include <bits/stdc++.h>
using namespace std;

long long mod;

long long multiply(long long a, long long b){
    if(b == 0){
        return 1;
    }
    else if(b == 1){
        return a%mod;
    }

    else if(b%2 == 0){
        long long temp = multiply(a, b/2);
        return (temp * temp)%mod;
    }
    else{
        return (a * multiply(a, b-1))%mod;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    long long a, b;
    cin >> a >> b >> mod;
    cout << multiply(a, b);

}
