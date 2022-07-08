#include <bits/stdc++.h>
using namespace std;

struct building{
    int left, height, right;
};

struct point{
    int x, y;
};

bool compare(building u, building v){
    return make_tuple(u.left, u.right, u.height) < make_tuple(v.left, v.right, v.height);
}

void append(vector<point> & a, point p){
    int n = a.size();
    if(n != 0){
        //Skip the point since this exists inbetween points
        if(p.y == a[n-1].y){
            return;
        }
        if(p.x == a[n-1].x){
            //Choose a bigger y as a replacement
            a[n-1].y = p.y;
            return;
        }
    }
    a.push_back(p);
}

vector<point> merge(vector<point> & left, vector<point> & right){
    int l = 0, r = 0;
    int left_size = left.size(), right_size = right.size();
    int left_height = 0, right_height = 0;

    vector<point> ans;
    
    //h is the current height of the building
    //One with smallest x is appended first using a function
    while(l < left_size && r < right_size){
        if(left[l].x < right[r].x){
            left_height = left[l].y;
            int h = max(left_height, right_height);
            append(ans, {left[l].x, h});
            l++;
        }
        else{
            right_height = right[r].y;
            int h = max(left_height, right_height);
            append(ans, {right[r].x, h});
            r++;
        }
    }

    while(l < left_size){
        append(ans, left[l]);
        l++;
    }
    while(r < right_size){
        append(ans, right[r]);
        r++;
    }
    return ans;

}

vector<point> split(int start, int end, vector<building> & b){
    //Split and merge together like merge sorting
    if(start == end){
        return {{b[start].left, b[start].height}, {b[start].right, 0}};
    }
    int mid = (start+end)/2;
    vector<point> left = split(start, mid, b);
    vector<point> right = split(mid+1, end, b);
    return merge(left, right);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int building_num;
    cin >> building_num;

    vector<building> buildings(building_num);
    for(int i = 0; i < building_num; i++){
        int l,h,r;
        cin >> l >> h >> r;
        buildings[i] = {l, h, r};
    }
    
    //Sort the list before merging
    sort(buildings.begin(), buildings.end(), compare);
    vector<point> ans = split(0, building_num-1, buildings);
    
    for(point ch: ans){
        cout << ch.x << " " << ch.y << " ";
    }

}
