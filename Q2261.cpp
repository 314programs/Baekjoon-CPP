#include <bits/stdc++.h>
using namespace std;

struct point{
    int x,y;
};

bool compare_x(point u, point v){
    return u.x < v.x;
}

bool compare_y(point u, point v){
    return u.y < v.y;
}

//Returns distance
int dist(point a, point b){
    return pow((b.x - a.x),2) + pow((b.y - a.y),2);
}

int brute_force(int start, int end, vector<point> & p){
    int ans = -1;
    for(int i = start; i < end; i++){
        for(int j = i + 1; j <= end; j++){
            int d = dist(p[i], p[j]);
            if(ans == -1 || ans > d){
                ans = d;
            }
        }
    }
    return ans;
}

int solve(int start, int end, vector<point> & p){
    int size_ = end - start + 1;
    //If size if smaller then 3, find the shortest distance by brute force
    if(size_ <= 3){
        return brute_force(start, end, p);
    }

    int mid = (start+end)/2;
    //Divide and combine
    int left = solve(start, mid, p);
    int right = solve(mid+1, end, p);
    int ans = min(left, right);
  
    //Create a grey zone from middle with width of ans*2
    //This ensures that not all items have to be checked
    vector<point> grey;
    for(int i = start; i <= end; i++){
        int d = p[i].x - p[mid].x;
        if(d*d < ans){
            grey.push_back(p[i]);
        }
    }

    int grey_size = grey.size();
    //Sort by y for easier comparison && time reduction
    sort(grey.begin(), grey.end(), compare_y);
    
    //Inside the grey area, find the minimum distance and compare it with current answer
    for(int i = 0; i < grey_size; i++){
        for(int j = i+1; j < grey_size; j++){
            int y = grey[i].y - grey[j].y;
            if(y*y < ans){
                int d = dist(grey[i], grey[j]);
                ans = min(ans, d);
            }
            else{
                break;
            }
        }
    }
    
    return ans;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    vector<point> p(n);
    for(int i = 0; i < n; i++){
        int x_, y_;
        cin >> x_ >> y_;
        p[i] = {x_, y_};
    }
    
    //Order points by x
    sort(p.begin(), p.end(), compare_x);
    cout << solve(0, n-1, p);

}
