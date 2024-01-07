//Used old code
//Will update the method on blog

#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int list_len;
    cin >> list_len;

    vector<int> store;
    for(int i = 0; i < list_len; i++){
        int num;
        cin >> num;
        auto current = lower_bound(store.begin(), store.end(), num);
        if(current == store.end()){
            store.push_back(num);
        }
        else{
            *current = num;
        }
    }

    cout << store.size();

}
