#include <bits/stdc++.h>
using namespace std;

char passcode_list[15];
vector<char> alphabet_list(15);
int check[15];

void backtrack(int num, int index_, int len_, int aeiou_num, int other_num){
    if(index_ == num){
        if(aeiou_num >= 1 && other_num >= 2){
            for(int i = 0; i < num; i++){
                cout << alphabet_list[passcode_list[i]];
            }
            cout << "\n";
        }  
        return;
    }

    for(int i = 0; i < len_; i++){
        if(check[i] != -1 && (index_ == 0 || alphabet_list[passcode_list[index_-1]] < alphabet_list[i])){
            
            
            check[i] = -1;
            passcode_list[index_] = i;
            if(alphabet_list[i] == 'a' || alphabet_list[i] == 'e' || alphabet_list[i] == 'i' || alphabet_list[i] == 'o' || alphabet_list[i] == 'u'){
                backtrack(num, index_+1, len_, aeiou_num+1, other_num);
            }
            else{
                backtrack(num, index_+1, len_, aeiou_num, other_num+1);
            }
            
            check[i] = 0;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int passcode_len, list_len;
    cin >> passcode_len >> list_len;


    for(int i = 0; i < list_len; i++){
        cin >> alphabet_list[i];
    }

    sort(alphabet_list.begin(), alphabet_list.begin() + list_len);
    backtrack(passcode_len, 0, list_len, 0, 0);
    
}
