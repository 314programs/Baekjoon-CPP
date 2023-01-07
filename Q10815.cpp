#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int owning_card_num, wanted_card_num;
    cin >> owning_card_num;

    vector<int> owning(owning_card_num);

    for(int i = 0; i < owning_card_num; i++){
        cin >> owning[i];
    }
    sort(owning.begin(), owning.end());

    cin >> wanted_card_num;
    for(int i = 0; i < wanted_card_num; i++){
        int want_num;
        cin >> want_num;

        int left = 0, right = owning_card_num-1;
        int middle;
        int found = 0;

        while(left <= right){
            middle = (left + right)/2;
            if(owning[middle] == want_num){
                found = 1;
                break;
            } 
            else if(owning[middle] < want_num){
                left = middle + 1;
            }
            else if(owning[middle] > want_num){
                right = middle - 1;
            }
        }
        cout << found << " ";

    }

}
