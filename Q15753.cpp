#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long
 
int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    bool can = true;
    int maximum = 0;
    int minimum = 0;
    a[0] = 0;

    for(int i = 1; i < n; i++){
        if(a[i] != -1){
            for(int j = a[i]-1; j >= 0; j--){
                //Mark down the days before breakout
                //If they don't match, the data is wrong
                if(a[i-(a[i]-j)] != -1 && a[i-(a[i]-j)] != j){
                    can = false;
                    break;
                }
                a[i-(a[i]-j)] = j;
            }
        }
    }

    if(can){
        for(int i = 0; i < n; i++){
            if(a[i] == 0){
                minimum++;
            }
            if(a[i] == -1){
                maximum++;
            }
        }
        cout << minimum << " " << maximum+minimum;
    }
    else{
        cout << -1;
    }
 
}
