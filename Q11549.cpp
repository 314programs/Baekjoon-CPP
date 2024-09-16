#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int tea_type;
    cin >> tea_type;

    int cnt = 0;
    for(int i = 0; i < 5; i++){
        int temp;
        cin >> temp;
        if(temp == tea_type) cnt++;
    }
    cout << cnt;

}
