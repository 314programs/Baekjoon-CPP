//Did not expect to get this the first try...

#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long
 
int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    string s;
    cin >> s;

    int a[26][s.size()+1];
    for(int j = 0; j < 26; j++){
        a[j][0] = 0;
    }
    
    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < 26; j++){
            a[j][i+1] = a[j][i];
            if(s[i]-'a' == j){
                a[j][i+1]++;
            }
        }
    }

    int n;
    cin >> n;
    while(n--){
        char ch;
        int s, e;
        cin >> ch >> s >> e;
        cout << a[ch-'a'][e+1]-a[ch-'a'][s] << "\n"; 
    }

}
