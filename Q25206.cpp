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

    float total = 0;
    float div = 0;

    for(int i = 0; i < 20; i++){
        string name;
        float n;
        string score;
        cin >> name >> n >> score;

        if(score == "P") continue;
        total += n * calc_score(score);
        div += n;
    }
    cout << fixed << setprecision(6) << total/div;


}
