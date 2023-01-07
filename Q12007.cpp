//I thought I could use average of values as middle point for some reason
//I need to practice more geometry
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

struct point{
    int x, y;
};

bool compare_x(point &u, point &v){
    if(u.x == v.x){
        return u.y < v.y;
    }
    return u.x > v.x;
}

bool compare_y(point &u, point &v){
    if(u.y == v.y){
        return u.x < v.x;
    }
    return u.y > v.y;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    ifstream cin;
    ofstream cout;
    cin.open("reduce.in");
    cout.open("reduce.out");

    int n;
    cin >> n;
    vector<point> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i].x >> a[i].y;
    }

    sort(a.begin(), a.end(), compare_x);
    int ans = 100000000;
    int min_x = 40001, min_y = 40001;
    int max_x = -1, max_y = -1;

    for(int i = 0; i < n; i++){
        min_x = min(min_x, a[i].x);
        min_y = min(min_y, a[i].y);
        max_x = max(max_x, a[i].x);
        max_y = max(max_y, a[i].y);
    }
    ans = abs(max_x - min_x) * abs(max_y - min_y);

    set<int> remove;
    for(int i = 0; i < n; i++){
        if(a[i].x == max_x || a[i].x == min_x){
            remove.insert(i);
        }
        if(a[i].y == max_y || a[i].y == min_y){
            remove.insert(i);
        }
    }

    for(auto ch: remove){
        min_x = 40001, min_y = 40001;
        max_x = -1, max_y = -1;
        for(int i = 0; i < n; i++){
            if(i == ch) continue;
            min_x = min(min_x, a[i].x);
            min_y = min(min_y, a[i].y);
            max_x = max(max_x, a[i].x);
            max_y = max(max_y, a[i].y);
        }
        ans = min(abs(max_x - min_x) * abs(max_y - min_y), ans);
    }

    cout << ans;


}
