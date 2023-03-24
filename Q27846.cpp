#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long

bool check(int w, vector<int> &a, vector<int> &b, vector<int> &c, int x, int y, int n){
    int lx = max(1LL, x-w);
    int hx = min(x+y-w-1LL, x);

    for(int i = 0; i < n; i++){
        int A = a[i], B = b[i], C = c[i];
        int D = x + y - w;
        
        if(B - A > 0){
            lx = max(lx, (-C + B*D + (B-A-1))/(B-A));
        }
        else if(A - B > 0){
            hx = min(hx, (C - B*D)/(A-B));
        }
        else{
            if(A*D > C){
                return false;
            }
        }
    }
    return (lx <= hx);

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
 
    int tc;
    cin >> tc;

    while(tc--){
        cin.ignore();

        int n, x, y;
        cin >> n >> x >> y;
        
        vector<int> a, b, c;
        for(int i = 0; i < n; i++){
            int d, e, f;
            cin >> d >> e >> f;
            a.push_back(d);
            b.push_back(e);
            c.push_back(f);
        }

        int low = 0;
        int high = x+y-2;

        while(high > low){
            int mid = (high+low)/2;
            if(check(mid, a, b, c, x, y, n)){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        cout << low << "\n";
    }

}
