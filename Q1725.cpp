#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct point{
    ll height, idx;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    ll ans = 0;
    stack<point> s;
    for(int i = 0; i < n; i++){
        //Must be in an increasing order, else delete top of the stack until it is increasing order
        while(!s.empty() && s.top().height > a[i]){
            ll cur_height = s.top().height;
            s.pop();
            
            //No bars behind means that this is the smallest
            ll cur_width = i;
            //There is a bar behind it that is shorter then the current bar
            if(!s.empty()) cur_width = i - s.top().idx-1;
            ans = max(ans, cur_height * cur_width);
            
        }
        s.push((point){a[i], i});
    }

    while(!s.empty()){
        ll cur_height = s.top().height;
        s.pop();

        ll cur_width = n;
      
        //There is a bar behind that is shorter then the current
        if(!s.empty()) cur_width = n - s.top().idx-1;
        //No bar behind
        ans = max(ans, cur_height * cur_width);
    }

    cout << ans;

}
