#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    string s1, s2;
    cin >> s1 >> s2;

    int ans = 0;
    bool reverse = false;
    for(int i = 0; i < n; i++){
        if(s1[i] != s2[i] && reverse == false){
            reverse = true;
            ans++;
        }
        else if(s1[i] == s2[i] && reverse == true){
            reverse = false;
        }
    }
    cout << ans;


}
