#include <bits/stdc++.h>
using namespace std;

//Goes over long long limit, so have to use string!?!
string add(string a, string b){
    //Reverse them to get the smallest digit at index 0
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string c = "";
    int carry = 0;

    while(a.length() < b.length()){
        a += "0";
    }
    while(a.length() > b.length()){
        b += "0";
    }

    int len = a.length();
    //Addition...
    for(int i = 0; i < len; i++){
        int temp = (a[i]-'0') + (b[i]-'0') + carry;
        c += (char)(temp%10 + '0');
        carry = temp/10;
    }
    if(carry){
        c += (char)(carry + '0');
    }
    reverse(c.begin(), c.end());
    return c;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    vector<string> DP(10001);
    DP[0] = "1";
    DP[1] = "1";
    DP[2] = "3";
    
    //Circular DP
    //Lucas number...
    for(int i = 3; i <= 10000; i++){
        DP[i] = add(DP[i-1], DP[i-2]);
    }

    int n;
    while(cin >> n){
        cout << DP[n] << "\n";
    }
}
