#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    int cnt = 0;
    while(n != 0){
        if(n&1) cnt++;
        n = n >> 1;
    }
    cout << cnt;
    

}
