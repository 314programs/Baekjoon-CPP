//On my way for pho
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int tc;
    cin >> tc;

    while(tc--){
        int len, wid;
        cin >> len >> wid;

        string s = "";
        for(int i = 0; i < len; i++){
            s += "X";
        }
        for(int i = 0; i < wid; i++) cout << s << "\n";
        cout << "\n";
    }

}
