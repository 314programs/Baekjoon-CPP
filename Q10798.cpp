#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    vector<string> s(5);
    for(int i = 0; i < 5; i++){
        cin >> s[i];
    }

    for(int x = 0; x < 15; x++){
        for(int y = 0; y < 5; y++){
            if(s[y][x] != '\0') cout << s[y][x];
        }
    }

}
