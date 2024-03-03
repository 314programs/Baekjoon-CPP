//rest
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    while(true){
        int num;
        cin >> num;
        if(num == -1) break;

        vector<int> factors;
        int cnt = 0;
        for(int i = 1; i < num; i++){
            if(num%i == 0){
                factors.push_back(i);
                cnt += i;
            }
        }

        if(cnt == num){
            cout << num << " = ";
            for(int i = 0; i < factors.size()-1; i++){
                cout << factors[i] << " + ";
            }
            cout << factors[factors.size()-1];
            cout << "\n";
        }
        else{
            cout << num << " is NOT perfect.\n";
        }
        

    }

}
