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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int cases;
    cin >> cases;

    while(cases--){
        int a,b;
        int GCD_;
        cin >> a >> b;
        GCD_ = gcd(a,b);

        cout << (a*b)/GCD_ << "\n";
    }
    

}
