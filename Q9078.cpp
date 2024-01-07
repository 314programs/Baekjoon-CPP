//Inversion numbers...
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
        
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(a[i] < a[j]) cnt++;
            }
        }

        if(cnt%2 == 0) cout << "YES\n";
        else cout << "NO\n";
    }

}
