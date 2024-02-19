#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int a,b,c,d;
    cin >> a >> b >> c >> d;
    
    //Conver to string
    string ab = to_string(a) + to_string(b);
    string cd = to_string(c) + to_string(d);
     
    //Convert to long long
    long long ab_ = stoll(ab);
    long long cd_ = stoll(cd);
    cout << ab_+cd_;

}
