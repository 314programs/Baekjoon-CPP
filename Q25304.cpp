#include <bits/stdc++.h>
using namespace std;


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int total;
    cin >> total;

    int count_;
    cin >> count_;

    int ans = 0;

    while(count_ --){
        int price, amount;
        cin >> price >> amount;
        ans += price * amount;
    }

    if(ans == total) cout << "Yes";
    else cout << "No";
}
