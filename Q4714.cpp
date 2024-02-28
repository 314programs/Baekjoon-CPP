//Almost done with backtracking now...

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while(true){
        float f;
        cin >> f;
        if(f == -1) break;

        cout << fixed << setprecision(2) << "Objects weighing " << f << " on Earth will weigh " << f*0.167 << " on the moon." <<"\n";
    }

}
