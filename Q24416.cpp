#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

ll cnt = 0;
int fib(int n){
    if(n == 1 || n == 2){
        cnt++;
        return 1;
    }
    else return fib(n-1) + fib(n-2);
}

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int n;
    cin >> n;
    fib(n);

    cout << cnt << " " << n-2;

}
