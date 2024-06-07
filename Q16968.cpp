#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    string in;
    getline(cin, in);

    int d_count = 0, c_count = 0;
    int ans = 1;
    for(auto ch: in){
        if(ch == 'd'){
            d_count++;
            if(d_count >= 2){
                ans *= 9;
            }
            else{
                ans *= 10;
            }
            c_count = 0;
        }
        else{
            c_count++;
            if(c_count >= 2){
                ans *= 25;
            }
            else{
                ans *= 26;
            }
            d_count = 0;
        }
    }

    cout << ans;

}
