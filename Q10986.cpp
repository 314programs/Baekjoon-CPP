#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<ll> s(n+1);
    s[0] = 0;

    for(int i = 1; i <= n; i++){
        int num;
        cin >> num;
        s[i] = s[i-1] + num;
        s[i] %= m;
    }

    map<int, int> cnt;
    cnt[0] = 1;
    ll ans = 0;

    //s[j] - s[i-1] = m
    //s[j] - m = s[i-1]
    for(int j = 1; j <= n; j++){
        ans += cnt[s[j]];
        cnt[s[j]] += 1;
    }
    cout << ans;

}


//Another method (faster)
#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<ll> s(n+1);
    map<int, int> cnt;

    cnt[0] = 1;
    s[0] = 0;

    for(int i = 1; i <= n; i++){
        int num;
        cin >> num;
        s[i] = s[i-1] + num;
        s[i] %= m;
        cnt[s[i]] += 1;
    }

    ll ans = 0;
    for(int i = 0; i < m; i++){
        //Add all possible combinations for 1 type of remainder
        ans += (ll)cnt[i] * (ll)(cnt[i]-1)/2LL;
    }

    cout << ans;

}
