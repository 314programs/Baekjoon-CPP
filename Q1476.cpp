#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int e,s,m;
    cin >> e >> s >> m;
    e -= 1;
    s -= 1;
    m -= 1;

    int year = 0;

    while(true){
        if(year%15 == e && year%28 == s && year%19==m){
            break;
        }
        year++;

    }
    cout << year+1;

}
