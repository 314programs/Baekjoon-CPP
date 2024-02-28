//Tired
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string num;
    cin >> num;
    long long ans = 0;

    for(char ch : num){
        ch -= '0';
        ans += pow(ch, 5);
    }

    cout << ans;

}
