#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int list_len;
    cin >> list_len;

    vector<int> store;
    for(int i = 0; i < list_len; i++){
        int num;
        cin >> num;
      
        auto current = lower_bound(store.begin(), store.end(), num);
        //If the current number is bigger then all, place it infront
        if(current == store.end()){
            store.push_back(num);
        }
        //If not, replace the bigger value (current) with the smaller value (num)
        else{
            *current = num;
        }
    }

    cout << store.size();

}
