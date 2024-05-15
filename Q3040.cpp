#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
#define int long long

void setIO(string s = ""){
	if(s == "") return;
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}


int32_t main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    vector<int> a(9);
    int sum = 0;
    for(int i = 0; i < 9; i++){
        cin >> a[i];
        sum += a[i];
    }

    int no1 = -1;
    int no2 = -11;

    for(int i = 0; i < 9; i++){
        for(int j = i+1; j < 9; j++){
            if(sum - a[i] - a[j] == 100){
                no1 = i;
                no2 = j;
                break;
            }
        }
    }

    for(int i = 0; i < 9; i++){
        if(i != no1 && i != no2){
            cout << a[i] << "\n";
        }
    }

}
