#include <bits/stdc++.h>
using namespace std;

int list_len;

int calc(vector<int> & numlist){
    int ans = 0;
    for(int i = 1; i < numlist.size()-1; i++){
        int energy = numlist[i-1] * numlist[i+1];
        vector<int> next_list(numlist);
        //Learned how to erase
        next_list.erase(next_list.begin() + i);
        energy += calc(next_list);
        ans = max(energy, ans);
    }

    return ans;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> list_len;
    vector<int> num_list(list_len);
    for(int i = 0; i < list_len; i++){
        cin >> num_list[i];
    }
    cout << calc(num_list);
}


