#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    int odd = 0, even = 0;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];

        if(a[i]%2 == 0) even++;
        else odd++;
    }

    int ans = 0;
    while(true){
        //Even set
        if(even > 0){
            even--;
        }
        else{
            if(odd >= 2){
                odd -= 2;
            }
            else if(odd == 1){
                ans--;
                break;
            }
            else{
                break;
            }
        }
        ans++;

        //Odd set
        if(odd > 0){
            odd--;
        }
        else{
            break;
        }
        ans++;
    }
    cout << max(ans, 0);

}
