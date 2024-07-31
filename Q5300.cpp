//I need to practice more cf
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

char a[10][10];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cout << i << " ";
        if(i%6 == 0){
            cout << "Go! ";
        }
    }
    if(n%6 != 0) cout << "Go! ";
 
}
 
