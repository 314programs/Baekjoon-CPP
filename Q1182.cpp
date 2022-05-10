//56ms bitmasking
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int listsize, num_over;
    cin >> listsize >> num_over;

    int count_ = 0;

    int numlist[20];
    for(int i = 0; i < listsize; i++){
        cin >> numlist[i];
    }

    for(int i = 1; i < (1 << listsize); i++){
        int sum_ = 0;
        for(int j = 0; j < listsize; j++){
            //Don't mistake and operator with &&
            if(i&(1 << j)){
                sum_ += numlist[j];
            }
        }
        if(sum_ == num_over){
            count_ += 1;
        }
    }

    cout << count_;
    
}

//4ms recursion
#include <bits/stdc++.h>
using namespace std;

vector<int> store_list;
int list_size, wanted_num;
int ans = 0;

void backtrack_(vector<int> & numbers, int idx, int count_){
    if(idx == list_size){
        if(count_ == wanted_num) ans += 1;
        return;
    }

    backtrack_(numbers, idx+1, count_ + numbers[idx]);
    backtrack_(numbers, idx+1, count_);

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> list_size >> wanted_num;

    vector<int> num_list(list_size);
    for(int i = 0; i < list_size; i++){
        cin >> num_list[i];
    }

    backtrack_(num_list, 0, 0);
    if(wanted_num == 0) ans -= 1;
    cout << ans;

}


