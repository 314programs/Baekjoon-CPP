#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

struct point{
    ll x, y;
};
point a[50000];
int n;

struct fence{
    ll area;
    vector<vector<int>> border;
};

//Function to calculate the borders and the area
//Remove vector indicates which index is not being used
fence calc(vector<int> remove){
    ll min_x = 50001, min_y = 50001;
    ll max_x = -50001, max_y = -50001;
    
    //Find mininum and maximum x and y values
    for(int i = 0; i < n; i++){
        //If index was supposed to be removed
        bool skip = false;
        for(auto ch: remove){
            if(i == ch){
                skip = true;
                break;
            }
        }
        if(skip) continue;

        min_x = min(min_x, a[i].x);
        max_x = max(max_x, a[i].x);
        min_y = min(min_y, a[i].y);
        max_y = max(max_y, a[i].y);
    }
    
    //Calculate area
    fence new_fence;
    new_fence.area = (max_x - min_x) * (max_y - min_y);
    vector<int> up, down, left, right;

    for(int i = 0; i < n; i++){
        bool skip = false;
        for(auto ch: remove){
            if(i == ch){
                skip = true;
                break;
            }
        }
        if(skip) continue;
        
        //Possible borders that can be set
        //Push indexes as we will remove values at the borders
        if(a[i].x == min_x) left.push_back(i);
        if(a[i].x == max_x) right.push_back(i);
        if(a[i].y == min_y) down.push_back(i);
        if(a[i].y == max_y) up.push_back(i);
        
    }
    
    //If vector's size is greater than 4, it is no use as we can only remove 3
    if(up.size() <= 3) new_fence.border.push_back(up);
    if(down.size() <= 3) new_fence.border.push_back(down);
    if(left.size() <= 3) new_fence.border.push_back(left);
    if(right.size() <= 3) new_fence.border.push_back(right);

    return new_fence;

}



int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i].x >> a[i].y;
    }
    
    //Calculate initial borders to use
    fence ini_f = calc(vector<int> ());
    ll ans = ini_f.area;
    
    //Only repeat 3 times as maximum of 3 cows can be selected
    //The loop repeats 3 times if there is 1 cow for each of the sides
    for(vector<int> side1: ini_f.border){
        fence calc_1 = calc(side1);
        ans = min(calc_1.area, ans);
        
        //Calculate another border for current one
        for(vector<int> side2: calc_1.border){
            //Number of cows not over 3, so recalculate possible borders from the first border(exclude)
            if(side1.size() + side2.size() <= 3){
                for(auto ch: side1){
                    side2.push_back(ch);
                }
                fence calc_2 = calc(side2);
                ans = min(calc_2.area, ans);
                
                //Number of cows not over 3, so recalculate possible borders from the second + first border(exclude)
                for(vector<int> side3: calc_2.border){
                    if(side2.size() + side3.size() <= 3){
                        for(auto ch: side2){
                            side3.push_back(ch);
                        }
                        fence calc_3 = calc(side3);
                        ans = min(calc_3.area, ans);
                    }
                }
            }
        }
    }

    cout << ans;


}
