//Math exam soon :skull:
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

string solve(vector<int> a){
    if(a[0] != 8 && a[0] != 9) return "answer";
    if(a[1] != a[2]) return "answer";
    if(a[3] != 8 && a[3] != 9) return "answer";
    return "ignore";
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    vector<int> a(4);
    for(int i = 0; i < 4; i++){
        cin >> a[i];
    }

    cout << solve(a);

}
