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
        int n;
        cin >> n;

        int temp = n - 25*(n/25) - 10*((n - 25*(n/25))/10);
        cout << n/25 << " " << (n - 25*(n/25))/10 << " " << temp/5 << " " << n%5 << "\n";
    }


}
