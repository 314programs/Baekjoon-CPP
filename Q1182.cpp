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

