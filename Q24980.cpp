#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

//I find ad hoc difficult, had to look at the editorial for this one

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;
    //Start from the end cause they have to be reversed first...
    for(int i = n-1; i >= 0; i-=2){
        //s[i] = even, s[i-1] odd
        //If odd is g and even is h, have to reverse it, must be in original position in order for flip to happen (ans%2 == 0)
        if(s[i-1] == 'G' && s[i] == 'H' && ans%2 == 0){
            ans++;
        }
        
        //If even is g and odd is h, don't have to reverse it, must be in flipped position in order for the flip to happen (ans%2 == 1)
        if(s[i-1] == 'H' && s[i] == 'G' && ans%2 == 1){
            ans++;
        }
    }
    cout << ans;

}
