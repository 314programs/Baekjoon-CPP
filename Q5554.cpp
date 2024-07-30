#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int seconds = 0;
    
    for(int i = 0; i < 4; i++){
        int temp;
        cin >> temp;
        seconds += temp;
    }
    cout << seconds/60 << "\n" << seconds%60;

}

