#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

ll gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}
 
int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<ll>());

    vector<ll> diff(n-1);
    ll gcf;
    //(gcf * x + R) - (gcf * y + R) = gcf * n
    for(int i = 0; i < n-1; i++){
        diff[i] = a[i] - a[i+1];
    }
    sort(diff.begin(), diff.end());
    
    //Find greatest common factor
    gcf = diff[0];
    for(int i = 1; i < n-1; i++){
        gcf = gcd(gcf, diff[i]);
    }

    set<ll> s;
    //Use sqrt to reduce time
    for(int i = 2; i <= sqrt(gcf)+1; i++){
        if(gcf%i == 0){
            s.insert(i);
            s.insert(gcf/i);
        }
    }
    s.insert(gcf);

    for(auto ch: s){
        cout << ch << " ";
    }


}
