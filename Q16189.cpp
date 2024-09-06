//Other questions I did today don't contribute to solved.ac...

#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    string s;
    cin >> s;
    int n;
    cin >> n;

    map<char, int> m;
    for(auto ch: s){
        m[ch]++;
    }

    int odd = 0;
    for(int i = 0; i < 26; i++){
       if(m[char(i + 'a')]%2 == 1){
           odd++;
       }
    }

    if(odd > 1 && n%2 == 1){
        cout << "NO";
    }
    else{
        cout << "YES";
    }

}
