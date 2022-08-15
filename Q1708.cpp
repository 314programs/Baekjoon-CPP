//Convex hull
#include <bits/stdc++.h>
using namespace std;

struct point{
    long long x, y;
};

point p[100000];
point p0;

//CWW
int CCW(point p1, point p2, point p3){
    long long ans = p1.x*p2.y + p2.x*p3.y + p3.x*p1.y;
    ans -= p1.y*p2.x + p2.y*p3.x + p3.y*p1.x;

    if(ans == 0) return 0;
    else if(ans > 0) return 1;
    else return -1;
}

//Calculating distance
long long distance(point p1, point p2){
    long long dx = p1.x - p2.x;
    long long dy = p1.y - p2.y;
    return dx*dx + dy*dy;
}

//Sorting function
bool compare(const point &u, const point &v){
    int temp = CCW(p0, u, v);
    if(temp == 0){
        return distance(p0, u) <= distance(p0, v);
    }
    else{
        return temp == 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p[i].x >> p[i].y;
    }
    
    //Get point on most left and down
    p0 = p[0];
    for(int i = 1; i < n; i++){
        if(p[i].y < p0.y || (p[i].y == p0.y && p[i].x < p0.x)){
            p0 = p[i];
        }
    }
    
    //Sort by smallest angle the point makes with p0, if angles are equal, sort by distance
    sort(p, p+n, compare);
    vector<point> s;
    //Convex shape should always make anticlockwise angle with the points, so use smth like stack to make sure that every point makes anticlockwise angle
    for(int i = 0; i < n; i++){
        while(s.size() >= 2 && CCW(s[s.size()-2], s[s.size()-1], p[i]) <= 0){
            s.pop_back();
        }
        s.push_back(p[i]);
    }
    cout << s.size();

}
