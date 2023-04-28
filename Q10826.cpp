#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long

void setIO(string s = ""){
	if(s == "") return;
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}

string add(string a, string b){
    int carry = 0;
    string ans = "";
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for(int i = 0; i < b.length(); i++){
        int a_ = a[i] - '0';
        int b_ = b[i] - '0';
        int total = a_ + b_ + carry;

        carry = total/10;
        ans += (total%10) + '0';
    }
    for(int i = b.length(); i < a.length(); i++){
        int a_ = a[i] - '0';
        int total = a_ + carry;
        carry = total/10;
        ans += (total%10) + '0';
    }
    if(carry != 0) ans += (carry) + '0';
    reverse(ans.begin(), ans.end());
    return ans;
}

int32_t main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);
 
	setIO();

    int n;
    cin >> n;

    vector<string> a = {"0", "1"};
    for(int i = 2; i <= n; i++){
        a.push_back(add(a[i-1], a[i-2]));
    }
    cout << a[n];

}
