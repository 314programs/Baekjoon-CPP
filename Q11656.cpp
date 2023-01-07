#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string s;
    string list_[1000];
    cin >> s;
    int length = s.size();
    for(int i = 0; i < length; i++){
        #Make substring from i to end
        list_[i] = s.substr(i, length);
    }
    
    //Sort list until the list length
    sort(list_, list_+length);
    
    for(int i = 0; i < length; i++){
        cout << list_[i] << "\n";
    }


}
