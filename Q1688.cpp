#include <bits/stdc++.h>
using namespace std;

struct point{
    long long x, y;
};

using Line = pair<point, point>;

//Using CCW algorithm to find the intersection
int CCW(point p1, point p2, point p3){
    long long ans = p1.x*p2.y + p2.x*p3.y + p3.x*p1.y;
    ans -= p1.y*p2.x + p2.y*p3.x + p3.y*p1.x;

    if(ans == 0) return 0;
    else if(ans > 0) return 1;
    else return -1;
}

bool cross(Line l1, Line l2){
    int temp1 = CCW(l1.first, l1.second, l2.first) * CCW(l1.first, l1.second, l2.second);
    int temp2 = CCW(l2.first, l2.second, l1.first) * CCW(l2.first, l2.second, l1.second);
    return temp1 < 0 && temp2 < 0;
}

int interesction(point &p1, int n, vector<point> &p){
    //This is to see if these points are in a straight line and intersect
    //If they do return 1
    for(int i = 0; i < n; i++){
        int temp1 = CCW(p[i], p[i+1], p1);
        if(temp1 == 0){
            auto min_x = min(p[i].x, p[i+1].x);
            auto max_x = max(p[i].x, p[i+1].x);
            auto min_y = min(p[i].y, p[i+1].y);
            auto max_y = max(p[i].y, p[i+1].y);

            if(min_x <= p1.x && p1.x <= max_x){
                if(min_y <= p1.y && p1.y <= max_y){
                    return 1;
                }   
            }
        }
    }
    
    //Point with gradient where no lines would match
    point p0 = {1, 2147483647};
    int cnt = 0;
    //Count intersection for other lines of the polygon
    for(int i = 0; i < n; i++){
        Line l1 = {p0, p1};
        cnt += cross(l1, {p[i], p[i+1]});
    }
    return cnt%2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    vector<point> p(n);

    for(int i = 0; i < n; i++){
        long long x, y;
        cin >> x >> y;
        p[i] = {x, y};
    }
    p.push_back(p[0]);

    int m = 3;
    while(m--){
        point temp;
        cin >> temp.x >> temp.y;
        cout << interesction(temp, n, p) << "\n";
    }

}
