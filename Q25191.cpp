#include <bits/stdc++.h>
using namespace std;


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int chicken;
    int cola, beer;
    cin >> chicken;
    cin >> cola >> beer;

    int ans;
    ans = beer + (cola/2);
    cout << min(ans, chicken);
}
