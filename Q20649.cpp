#include <bits/stdc++.h>
using namespace std;

//Recycled code from bronze question
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

    sort(Up.begin(), Up.end(), compare_x);
    sort(Right.begin(), Right.end(), compare_y);
    
    //To find parent
    int stopped_by[1001];
    memset(stopped_by, -1, sizeof(stopped_by));

    for(point &r: Right){
        for(point &u: Up){
            if(u.x < r.x || r.y < u.y) continue;

            if(u.blocked_y != -1){
                //Right heading cow is stopped by up heading cow
                if(u.blocked_y > r.y && u.blocked_y - u.y > u.x - r.x){
                    stopped_by[r.idx] = u.idx;
                    break;
                }
            }
            else{
                long long r_need = u.x - r.x;
                long long u_need = r.y - u.y;
                if(r_need > u_need){
                    //Right heading cow is stopped by up heading cow
                    stopped_by[r.idx] = u.idx;
                    break;
                }
                else if(r_need < u_need && u.blocked_y == -1){
                    //Up heading cow is stopped by right heading cow
                    stopped_by[u.idx] = r.idx;
                    u.blocked_y = r.y;
                    u.blocked_x = u.x;
                }
            }
        }
    }

    int ans[1001];
    memset(ans, 0, sizeof(ans));
    //Keep finding parents and add the collisions
    for(int i = 0; i < n; i++){
        int j = stopped_by[i];
        while(j != -1){
            ans[j]++;
            j = stopped_by[j];
        }
    }
    
    for(int i = 0; i < n; i++){
        cout << ans[i] << "\n";
    }

}
