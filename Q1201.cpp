#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int length, increase_length, decrease_length;
    cin >> length >> increase_length >> decrease_length;
  
    //Cannot be made (Erdős-Szekeres Theorem) https://mathworld.wolfram.com/Erdos-SzekeresTheorem.html
    if(length < increase_length + decrease_length - 1 || length > increase_length*decrease_length){
        cout << -1;
        return 0;  
    }

    vector<int> ans(length);
    int group_num = increase_length;
    
    //Make list of answers
    for(int i = 1; i <= length; i++){
        ans[i-1] = i;
    }
    
    //Answer will be grouped into *increase_length* number of group and reversed
    //Maximum group length will be *decrease_length*
    vector<int> group;
    group.push_back(0);
    group.push_back(decrease_length);

    length -= decrease_length;
    group_num -= 1;

    int group_size, remainder;
    
    //Calculate size of each group, and the remainders
    if(group_num == 0){
        group_size = 1;
        remainder = 0;
    }

    else{
        group_size = length/group_num;
        remainder = length%group_num;
    }
    
    //If the remainder is above 0, add 1 to the group seperator and subtract 1 from remainder
    for(int i = 0; i < group_num; i++){
        if(remainder > 0){
            group.push_back(group.back() + 1 + group_size);
            remainder -= 1;
        }
        else{
            group.push_back(group.back() + group_size);
        }
    }
     
    //Reverse each group
    for(int i = 0; i < group.size() - 1; i++){
        reverse(ans.begin() + group[i], ans.begin() + group[i+1]);
    }
    //Print
    for(auto ch: ans){
        cout << ch << " ";
    }

}
