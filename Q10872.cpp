#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int num;
    int factorial = 1;
    cin >> num;

    for(int i = 1; i <= num; i++){
        factorial *= i;
    }

    cout << factorial;
    
}
