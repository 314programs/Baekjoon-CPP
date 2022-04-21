#include <bits/stdc++.h>
using namespace std;
int numlist[10000];

bool final(int len_){
    int i = len_-1;
    //While numlist[i-1] is not bigger
    while(i > 0 && numlist[i-1] < numlist[i]){
        i -= 1;
    }
    if(i <= 0){
        return false;
    }
    int j = len_-1;
    //Find the bigger number then numlist[i-1] from the left
    while(numlist[j] > numlist[i-1]){
        j -= 1;
    }
    swap(numlist[j], numlist[i-1]);
    j = len_-1;
    //Swapping stays the same
    while(i < j){
        swap(numlist[i], numlist[j]);
        i += 1;
        j -= 1;
    }
    return true;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int list_len;
    cin >> list_len;

    
    for(int i = 0; i < list_len; i++){
        cin >> numlist[i];
    }

    int print_ = final(list_len);

    if(print_ == false){
        cout << "-1";
    }
    else{
        for(int i = 0; i < list_len; i++){
            cout << numlist[i] << " ";
        }
    }
    
}
