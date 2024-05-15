#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int tc = 3;
    while(tc--){
        int num = 0;
        for(int i = 0; i < 4; i++){
            int temp;
            cin >> temp;
            num += temp;
        }

        if(num == 3){
            cout << "A\n";
        }
        else if(num == 2){
            cout << "B\n";
        }
        else if(num == 1){
            cout << "C\n";
        }
        else if(num == 0){
            cout << "D\n";
        }
        else{
            cout << "E\n";
        }
    }

}
