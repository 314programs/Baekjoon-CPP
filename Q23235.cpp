#include <bits/stdc++.h>
using namespace std;


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int case_ = 1;
    while(true){
        int list_len;
        cin >> list_len;

        if(list_len == 0) break;

        int temp;
        for(int i = 0; i < list_len; i++){
            cin >> temp;
        }
        cout << "Case " + to_string(case_) + ": Sorting... done!" + "\n";
        case_++;
    }

}
