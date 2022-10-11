#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> s(n+1);
    s[0] = 0;

    for(int i = 1; i <= n; i++){
        int num;
        cin >> num;
        s[i] = s[i-1] + num;
    }

    map<int, int> cnt;
    cnt[0] = 1;
    long long ans = 0;

    //s[j] - s[i-1] = m
    //s[j] - m = s[i-1]
    for(int j = 1; j <= n; j++){
        ans += cnt[s[j] - m];
        cnt[s[j]] += 1;
    }
    cout << ans;

}
