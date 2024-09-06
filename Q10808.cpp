#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string word;
    int alphabets[26];
    memset(alphabets, 0, 26*4);
    cin >> word;

    for(char ch: word){
        #(int)ch: convert character into a ascii code
        alphabets[(int)ch-97] += 1;
    }
    for(int i = 0; i < 26; i++){
        cout << alphabets[i] << " ";
    }

}
