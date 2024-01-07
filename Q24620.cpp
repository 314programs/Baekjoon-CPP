#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> s(n+1);
        s[0] = 0;

        bool same = true;
        //Sum them up into array s
        for(int i = 0; i < n; i++){
            cin >> a[i];
            s[i+1] = s[i] + a[i];
            if(i > 0 && a[i] != a[i-1]){
                same = false;
            }
        }

        if(same){
            cout << 0 << "\n";
        }
        //Since we want the values to be all same, we can find multiples of a specific number in a total sum
        //Indexes between the multiples will be added to the answer
        else{
            int ans = 1e9;
            for(int i = 1; i <= s[n]; i++){
                if(s[n]%i != 0) continue;
                
                int temp = 0;
                int next = i;
                int prev_idx = 0;

                for(int j = 1; j < n+1; j++){
                    if(s[j] == next){
                        temp += j - prev_idx - 1;
                        prev_idx = j;
                        next += i;
                    }
                }

                if(next != s[n]+i){
                    temp = 1e9;
                }
                else{
                    //Minimum multiple will require miminum addition
                    ans = temp;
                    break;
                }
            }

            cout << ans << "\n";
        }
        
    }

}
