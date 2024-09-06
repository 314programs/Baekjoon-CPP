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

float calc_score(string score){
    if(score == "F") return 0;
    else{
        float calc = 4 - (score[0] - 'A');
        if(score[1] == '+') calc += 0.5;
        return calc;
    }
}

int32_t main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    vector<int> a(3);
    for(int i = 0; i < 3; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int L1 = a[0] + a[1];
    int L2 = a[2];

    int eq = a[0] * 3;
    int other = 0;
    if(L1 > L2){
        //Turns out there is an exception of when you dont need to shorten any sides
        other = L1 + L2;
    }
    else{
        other = min(L1, L2)*2 - 1;
    }


    cout << max(other, eq);

}
