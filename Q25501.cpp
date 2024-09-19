//Finish up recursion problems..
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
        string s;
        cin >> s;
        
        int palin = 1;
        int cnt = 0;
        for(int i = 0; i < (s.size()/2); i++){
            if(s[i] != s[s.size()-i-1]){
                palin = 0;
                break;
            }
            cnt++;
        }
        cout << palin << " " << cnt+1 << "\n";
    }
}
