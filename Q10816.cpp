#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int have_card_num;
    cin >> have_card_num;
    vector<int> have_card(have_card_num);

    for(int i = 0; i < have_card_num; i++) cin >> have_card[i];
    sort(have_card.begin(), have_card.end());

    int count_card_num;
    cin >> count_card_num;
    
    while(count_card_num--){
        int ch;
        cin >> ch;
    
        int lower = -1, upper = -1;
        int left = 0, right = have_card_num-1;
        
        //Get lower and upper bound
        //Can be done with lower_bound(), upper_bound() but needed to learn how to make one
        //Lower bound = first number equal or bigger then the number given
        //upper bound = first number bigger then the number given
        while(left <= right){
            int mid = (left+right)/2;
            if(have_card[mid] == ch){
                lower = mid;
                right = mid - 1;
            }
            else if(have_card[mid] > ch){
                right = mid - 1;
            }
            else if(have_card[mid] < ch){
                left = mid + 1;
            }
        }

        left = 0, right = have_card_num-1;

        while(left <= right){
            int mid = (left+right)/2;
            if(have_card[mid] == ch){
                left = mid + 1;
                upper = mid;
            }
            else if(have_card[mid] > ch){
                right = mid - 1;
            }
            else if(have_card[mid] < ch){
                left = mid + 1;
            }
        }

        if(lower == -1) cout << 0 << " ";
        else cout << upper-lower+1 << " ";

    }


}
