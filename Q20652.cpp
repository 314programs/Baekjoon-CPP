#include <bits/stdc++.h>
using namespace std;

//While ago, I couldn't solve it at all
//But now I can
struct point{
    long long idx, x, y, blocked_x, blocked_y;
};

bool compare_x(point &u, point &v){
    return u.x < v.x;
}

bool compare_y(point &u, point &v){
    return u.y < v.y;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    vector<point> Up;
    vector<point> Right;

    for(int i = 0; i < n; i++){
        char dir;
        int start_x, start_y;
        cin >> dir >> start_x >> start_y;
        if(dir == 'N'){
            Up.push_back({i, start_x, start_y, -1, -1});
        }
        else{
            Right.push_back({i, start_x, start_y, -1, -1});
        }
    }
    
    //Sort Up by increasing x, so that it will be blocked/blocking first
    sort(Up.begin(), Up.end(), compare_x);
    //Sort Right by increasing y, so that it will be blocked/blocking first
    sort(Right.begin(), Right.end(), compare_y);

    vector<string> ans(n);


    for(point &r: Right){
        long long max_dist = 2e9;
        for(point &u: Up){
            if(u.x < r.x || r.y < u.y) continue;
            
            //If the north cow is blocked
            if(u.blocked_y != -1){
                if(u.blocked_y > r.y && u.blocked_y - u.y > u.x - r.x){
                    max_dist = min(u.x - r.x, max_dist);
                    break;
                }
            }
            else{
                long long r_need = u.x - r.x;
                long long u_need = r.y - u.y;
                //Cow heading up arrives first, blocking the right heading cow
                if(r_need > u_need){
                    max_dist = min(r_need, max_dist);
                    break;
                }
                //Cow heading right arrives first, blocking the up heading cow
                else if(r_need < u_need && u.blocked_y == -1){
                    //Update the blocked position
                    u.blocked_y = r.y;
                    u.blocked_x = u.x;
                }
            }
        }
        if(max_dist == 2e9) ans[r.idx] = "Infinity";
        else ans[r.idx] = to_string(max_dist);
    }
    
    //Update distance for up heading cows
    for(auto u: Up){
        if(u.blocked_y != -1){
            ans[u.idx] = to_string(u.blocked_y - u.y);
        }
        else{
            ans[u.idx] = "Infinity";
        }
    }


    for(auto ch: ans){
        cout << ch << "\n";
    }

}
