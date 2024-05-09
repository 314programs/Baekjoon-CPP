//Put this just in case of failure of planting grass using usaco
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--){
        int a, b;
        cin >> a >> b;
        cout << floor(a*b/2) << "\n";
    }

}
