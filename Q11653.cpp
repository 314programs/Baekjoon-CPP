#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int num;
    cin >> num;
    int temp = num;

    for(int i = 2; i * i <= temp; i++){
        while(num%i == 0){
            cout << i << "\n";
            num /= i;
        }
    }

    if(num != 1){
        cout << num;
    }

}
