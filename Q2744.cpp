#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string sentence;
    getline(cin, sentence);

    for(char ch: sentence){
        if(ch <= 90){
            printf("%c", ch + 32);
        }
        else if(ch == 32){
            cout << ' ';
        }
        else{
            printf("%c", ch - 32);
        }
    }

}
