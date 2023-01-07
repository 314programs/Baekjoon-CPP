#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    else{
        return gcd(b, a%b);
    }
}

int main(void){
    int a,b;
    int GCD_;
    cin >> a >> b;
    GCD_ = gcd(a,b);

    cout << GCD_ << "\n" << (a*b)/GCD_;

}
