#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    priority_queue<int> temp4;
    priority_queue<int> temp2;
    int ans = 0;
    for(int i = 0; i < 4; i++){
        int temp;
        cin >> temp;
        temp4.push(temp);
    }

    for(int i = 0; i < 2; i++){
        int temp;
        cin >> temp;
        temp2.push(temp);
    }

    for(int i = 0; i < 3; i++){
        ans += temp4.top();
        temp4.pop();
    }

    ans += temp2.top();
    cout << ans;

}
