#include <bits/stdc++.h>
using namespace std;

//Addition using strings
string add(string a, string b){
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    while(a.length() < b.length()){
        a += "0";
    }
    while(a.length() > b.length()){
        b += "0";
    }

    string ans = "";
    int carry;
    int len = a.length();

    for(int i = 0; i < len; i++){
        int temp = (a[i]-'0') + (b[i]-'0') + carry;
        ans += (char)(temp%10 + '0');
        carry = temp/10;
    }
    if(carry != 0){
        ans += (char)(carry + '0');
    }
    reverse(ans.begin(), ans.end());
    return ans;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string a, b;
    cin >> a >> b;
    
    cout << add(a, b);

}
