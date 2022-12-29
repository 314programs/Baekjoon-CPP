//How to solve game theory???

#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

const int mx = 5000001;
int min_turns[mx] = {0, 1};
bool sieve[mx] = {false};
int max_mod4[4] = {2, 1, 2, 3};

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    for(int i = 2; i < mx; i++){
        if(!sieve[i]){
            for(int j = i+i; j < mx; j += i){
                sieve[j] = true;
            }
            max_mod4[i%4] = i;
        }
        min_turns[i] = ((i - max_mod4[i%4])/2) + 1;
    }


    int tc;
    cin >> tc;

    while(tc--){
        int n;
        cin >> n;

        int moves = 1e9;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(min_turns[a[i]]/2 < moves/2) moves = min_turns[a[i]];
        }

        if(moves % 2) cout << "Farmer John\n";
        else cout << "Farmer Nhoj\n";
    }

}
