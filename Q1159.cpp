//365 day streak day!
//Will solve platinium later when I come back from celebration lunch
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int ppl_cnt;
    cin >> ppl_cnt;

    map<char, int> m;
    for(int i = 97; i <= 122; i++){
        m[char(i)] = 0;
    }

    while(ppl_cnt--){
        string name;
        cin >> name;

        m[name[0]]++;
    }
    
    bool print = false;
    for(int i = 97; i <= 122; i++){
        if(m[char(i)] >= 5){
            cout << char(i);
            print = true;
        }
    }

    if(!print) cout << "PREDAJA";
}
