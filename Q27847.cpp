#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long

struct point{
    int x, y, t;
};

bool can_reach(point &a, point &b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) <= (a.t-b.t)*(a.t-b.t);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int g, n;
    cin >> g >> n;
    int ans = 0;

    vector<point> garden(g);
    for(int i = 0; i < g; i++){
        cin >> garden[i].x >> garden[i].y >> garden[i].t;
    }
    sort(garden.begin(), garden.end(), [&](point &u, point &v){
        return u.t < v.t;
    });

    for(int i = 0; i < n; i++){
        point cur;
        cin >> cur.x >> cur.y >> cur.t;

        int left = 0, right = g-1;
        int pos = g;
        while(left <= right){
            int mid = (left+right)/2;
            if(garden[mid].t > cur.t){
                pos = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }

        bool innocent = false;
        for(int j = pos-1; j <= pos; j++){
            if(j >= 0 && j < g){
                innocent |= !can_reach(garden[j], cur);
            }
        }
        ans += (int)innocent;

    }
    cout << ans;

}
