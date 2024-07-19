#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int shop_cnt;
    cin >> shop_cnt;

    int ans = -1;
    for(int i = 0; i < shop_cnt; i++){
        int a,b;
        cin >> a >> b;
        if(a <= b){
            if(ans == -1 || ans > b){
                ans = b;
            }
        }
    }

    cout << ans;

}
