#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    long long num_list[91];
    num_list[0] = 0;
    num_list[1] = 1;

    int n;
    cin >> n;

    for(int i = 2; i <= n; i++){
        num_list[i] = num_list[i-1] + num_list[i-2];
    }
    cout << num_list[n];

}
