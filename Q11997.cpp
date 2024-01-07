#include <bits/stdc++.h>
using namespace std;

struct point{
    int x, y;
};

bool compare(point u, point v){
    return u.x < v.x;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    vector<point> a(n);
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }
    
    //Sort by x so that it can be sweeped
    sort(a.begin(), a.end(), compare);
    int ans = n;

    for(int i = 0; i < n; i++){
        vector<point> above;
        vector<point> below;
        
        //Firstly, put a horizontal fence
        for(int j = 0; j < n; j++){
            if(a[j].y <= a[i].y){
                below.push_back(a[j]);
            }
            else{
                above.push_back(a[j]);
            }
        }
        int below_idx = 0;
        int above_idx = 0;
        //Sweeping using the x_coordinates of cows
        while(below_idx < below.size() || above_idx < above.size()){
            int x_border = 2e9;
            //the idxs show how many cows are in one region of fence
            //Find the minimum x values out of the two lists, move the fence left to right
            if(below_idx < below.size()){
                x_border = min(x_border, below[below_idx].x);
            }
            if(above_idx < above.size()){
                x_border = min(x_border, above[above_idx].x);
            }
            
            //Move the cows to another region by increasing the idx, which will increase x_border
            //While is used just in case x coordinates are equal
            while(below_idx < below.size() && below[below_idx].x == x_border){
                below_idx++;
            }
            while(above_idx < above.size() && above[above_idx].x == x_border){
                above_idx++;
            }
            //Find the maximum number of cows for this type of case
            ans = min(ans, max(max(below_idx, (int)below.size() - below_idx), max(above_idx, (int)above.size() - above_idx)));
        }
    }
    cout << ans;

}
