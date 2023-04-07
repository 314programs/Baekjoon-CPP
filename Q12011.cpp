#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long

struct cow{
	int x, y;
};

int calc(vector<cow> &a, int start, int end){
    cow low_left = {(int)1e9+1, (int)1e9+1};
    cow top_right = {0, 0};
    for(int i = start; i <= end; i++){
        low_left.x = min(low_left.x, a[i].x);
        low_left.y = min(low_left.y, a[i].y);
        top_right.x = max(top_right.x, a[i].x);
        top_right.y = max(top_right.y, a[i].y);
    }

    int area = (top_right.x - low_left.x) * (top_right.y - low_left.y);
    return area;
}

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    //USACO Input
    /*
    fstream cin;
    cin.open("split.in");
    ofstream cout;
    cout.open("split.out");
    */
    ///////////////////////////////////////////////////////////////////////////////

    int n;
    cin >> n;
    vector<cow> a(n);
    multiset<int> all_x, all_y;

    for(int i = 0; i < n; i++){
        cin >> a[i].x >> a[i].y;
        all_x.insert(a[i].x);
        all_y.insert(a[i].y);
    }
    int ini_area = calc(a, 0, n-1);

    sort(a.begin(), a.end(), [&](cow &u, cow &v){
        return u.x < v.x;
    });
    int cur_area = calc(a, 0, n-1);


    multiset<int> left_x, right_x, left_y, right_y;
    for(int k = 0; k <= 1; k++){
        left_x.clear();
        left_y.clear();
        right_x = all_x;
        right_y = all_y;

        for(int i = 0; i < n-1; i++){
            left_x.insert(a[i].x);
            left_y.insert(a[i].y);
            right_x.erase(right_x.find(a[i].x));
            right_y.erase(right_y.find(a[i].y));

            int left_area = (*left_x.rbegin() - *left_x.begin()) * (*left_y.rbegin() - *left_y.begin());
            int right_area = (*right_x.rbegin() - *right_x.begin()) * (*right_y.rbegin() - *right_y.begin());
            cur_area = min(left_area + right_area, cur_area);
        }

        sort(a.begin(), a.end(), [&](cow &u, cow &v){
            return u.y < v.y;
        });
    }

    cout << ini_area - cur_area;

}
