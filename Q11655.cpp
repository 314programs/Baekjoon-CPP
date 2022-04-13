#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string word;
    getline(cin, word);
    for(char ch:word){
        //Capital letter
        if(65<=(int)ch && (int)ch<=90){
            cout << (char)((((int)ch - 65 + 13)%26) + 65);
        }
        //Small letter
        else if(97<=(int)ch && (int)ch<=122){
            cout << (char)((((int)ch - 97 + 13)%26) + 97);
        }
        //Anything else
        else{
            cout << ch;
        }
    }

}
