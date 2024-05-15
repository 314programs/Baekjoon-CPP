#include <bits/stdc++.h>
using namespace std;


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int eight_box, three_box;
    cin >> eight_box;
    cin >> three_box;

    cout << (eight_box*8 + three_box*3) - 28;

}
