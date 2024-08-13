#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    vector<int> ppl(4);
    for(int i = 0; i < 4; i++){
        cin >> ppl[i];
    }

    int x, y, r;
    cin >> x >> y >> r;
    int ans = 0;
    for(int i = 0; i < 4; i++){
        if(ppl[i] == x){
            ans = i+1;
        }
    }
    cout << ans;

}
