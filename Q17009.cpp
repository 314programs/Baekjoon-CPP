#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int a_3, a_2, a_1;
    int b_3, b_2, b_1;

    cin >> a_3 >> a_2 >> a_1 >> b_3 >> b_2 >> b_1;
    int a, b;
    a = (a_3*3) + (a_2*2) + a_1;
    b = (b_3*3) + (b_2*2) + b_1;

    if(a > b) cout << "A";
    else if(a < b) cout << "B";
    else cout << "T";
}
