#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int s;
    int num;

    cin >> s >> num;
    stack<char> result;

    while(true){
        int temp = s%num;
        s /= num;

        if(0 <= temp && temp <= 9){
            result.push(temp + '0');
        }
        else{
            result.push(temp + '7');
        }
        
        if(s == 0){
            break;
        }
        
    }
    
    while(!result.empty()){
        cout << result.top();
        result.pop();
    }

}
