#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    set<string> st;
    string s;
    cin >> s;
    int n = s.size();
    //Instead of substr, I could have used other ways to make it faster...
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n-i; j++){
            st.insert(s.substr(j, i));
        }
    }
    cout << st.size();

}
