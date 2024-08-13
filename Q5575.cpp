//Will do codeforces today... so must do bronze again
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    for(int i = 0; i < 3; i++){
        int h1, m1, s1;
        int h2, m2, s2;
        cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
        
        int s = 0;
        s += (h2-h1)*60*60;
        s += (m2-m1)*60;
        s += s2-s1;

        int h = s/3600;
        s -= h*3600;
        int m = s/60;
        s -= m*60;

        cout << h << " " << m << " " << s << "\n";

    }


}
