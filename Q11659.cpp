#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int s[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    s[0] = 0;

    for(int i = 1; i <= n; i++){
        int num;
        cin >> num;
        s[i] = num + s[i-1];
    }

    while(m--){
        int i, j;
        cin >> i >> j;
        cout << s[j] - s[i-1] << "\n";
    }
}
