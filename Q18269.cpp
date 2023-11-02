#include <bits/stdc++.h>
using namespace std;

//Thought substr from start only... oops
//Had to look at solution to find out

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int n;
    string s;

    cin >> n;
    cin >> s;

    int ans = 0;
    //Length of sub string
    for(int i = 1; i <= n; i++){
        bool can = true;
        
        //x indicates substr that comes later
        //y indicates substr that comes first
        for(int x = 0; x + i <= n; x++){
            for(int y = 0; y < x; y++){
                if(s.substr(x, i) == s.substr(y, i)){
                    can = false;
                }
            }
        }

        if(can){
            cout << i;
            break;
        }
    }

}
