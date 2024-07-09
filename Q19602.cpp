#include <bits/stdc++.h>
using namespace std;


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int S, M, L;
    cin >> S;
    cin >> M;
    cin >> L;

    int happy = S + (M*2) + (L*3);
    if(happy >= 10){
        cout << "happy";
    }
    else{
        cout << "sad";
    }

}
