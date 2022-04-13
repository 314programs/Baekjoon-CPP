#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string word;
    int alphabets[26];
    memset(alphabets, -1, 26*4);
    cin >> word;
    
    //Using index just for convinience
    int index = 0;
    for(char ch: word){
        //To avoid overlap
        if(alphabets[(int)ch-97] == -1){
            alphabets[(int)ch-97] = index;
        }
        index++;
    }
    for(int i = 0; i < 26; i++){
        cout << alphabets[i] << " ";
    }

}
