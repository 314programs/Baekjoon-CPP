//I hate conversions
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string s;
    int num;

    cin >> s >> num;
    int pow_ = s.size()-1;
    int result = 0;

    for(char ch: s){
        if('0' <= ch && ch <= '9'){
            result += (ch - '0') * pow(num, pow_--);
            
        }
        else{
            
            result += (ch-'A'+10) * pow(num, pow_--);
        }
    }
    cout << result;

}
