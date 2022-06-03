#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int length, behind;
    cin >> length >> behind;

    vector<char> ans(length);
    int pairs = 0;
    int a_count = false;

    for(int i = 0; i < length; i++){
        ans[i] = 'B';
        
        //Adding A to the string
        if(pairs != behind && length - i - 1 - a_count <= behind - pairs){
            pairs += length - i - 1 - a_count;
            a_count += 1;
            ans[i] = 'A';
        }
    }
    
    //If there is no A, add it
    if(a_count == 0) ans[length-1] = 'A';

    if(a_count != length){
        for(auto ch: ans){
            cout << ch;
        }
    }
    //If the test is all A, it means the K value was too large/impossible
    else{
        cout << -1;
    }
    
}
