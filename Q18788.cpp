#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

//I tried reversing them all, but turns out its too slow for 1 single test case
int n, k, a1, a2, b1, b2;
int next(int cur){
    if(a1 <= cur && cur <= a2) cur = a1+a2-cur;
    if(b1 <= cur && cur <= b2) cur = b1+b2-cur;
    return cur;
}

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    ifstream cin;
    ofstream cout;
    cin.open("swap.in");
    cout.open("swap.out");

    cin >> n >> k >> a1 >> a2 >> b1 >> b2;
    vector<int> ans(n+1);

    for(int i = 1; i <= n; i++){
        int swaps = 1, cur = next(i);

        while(cur != i){
            swaps++;
            cur = next(cur);
        }

        int t = k%swaps;
        while(t--){
            cur = next(cur);
        }
        ans[cur] = i;
    }

    for(int i = 1; i <= n; i++){
        cout << ans[i] << "\n";
    }


}
