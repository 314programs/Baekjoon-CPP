#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while(true){
        string sentence;
        getline(cin, sentence);
        if(sentence == ""){
            break;
        }

        int small_alpha = 0;
        int big_alpha = 0;
        int num = 0;
        int space_ = 0;

        for(char ch:sentence){
            //space
            if((int)ch == 32){
                space_ += 1;
            }
            //number
            else if(48 <= (int)ch && (int)ch <= 57){
                num += 1;
            }
            //small alphabet
            else if(97 <= (int)ch && (int)ch <= 122){
                small_alpha += 1;
            }
            //big alphabet
            else if(65 <= (int)ch && (int)ch <= 90){
                big_alpha += 1;
            }

        }

        cout << small_alpha << " " << big_alpha << " " << num << " " << space_ << "\n";

    }

}
