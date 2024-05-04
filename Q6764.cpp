#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    vector<int> a(4);
    for(int i = 0; i < 4; i++){
        cin >> a[i];
    }

    if(a[0] < a[1] && a[1] < a[2] && a[2] < a[3]){
        cout << "Fish Rising";
    }
    else if(a[0] > a[1] && a[1] > a[2] && a[2] > a[3]){
        cout << "Fish Diving";
    }
    else if(a[0] == a[1] && a[1] == a[2] && a[2] == a[3]){
        cout << "Fish At Constant Depth";
    }
    else{
        cout << "No Fish";
    }

}
