//USE LONG LONG
//HOW MANY TIMES HAVE YOU NOT USED LONG LONG AND GOT IT WRONG

#include <bits/stdc++.h>
using namespace std;

long long dist_;
long long start_x, start_y, end_x, end_y;
int used[3];

struct coord{
    long long x, y;
};

coord start, end_;

//Simple function for distance calculation
long long calc_dist(coord a, coord b){
    return abs(a.x - b.x) + abs(a.y - b.y);
}

//Use every teleporter && make permutation and calculate distance for each
void solve(int idx, vector<coord> & tele_a, vector<coord> & tele_b, long long current_dist, coord current_pos){
    if(idx == 4) return;
    dist_ = min(current_dist + calc_dist(current_pos, end_), dist_);
    
    for(int i = 0; i < 3; i++){
        if(used[i] == 0){
            used[i] = 1;
            solve(idx+1, tele_a, tele_b, current_dist + calc_dist(current_pos, tele_a[i]) + 10, tele_b[i]);
            used[i] = 0;
        }
    }

    for(int i = 0; i < 3; i++){
        if(used[i] == 0){
            used[i] = 1;
            solve(idx+1, tele_a, tele_b, current_dist + calc_dist(current_pos, tele_b[i]) + 10, tele_a[i]);
            used[i] = 0;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> start_x >> start_y;
    cin >> end_x >> end_y;

    start = {start_x, start_y};
    end_ = {end_x, end_y};
    vector<coord> tele_a(3);
    vector<coord> tele_b(3);

    memset(used, 0, sizeof(used));

    for(int i = 0; i < 3; i++){
        int x_a, y_a, x_b, y_b;
        cin >> x_a >> y_a >> x_b >> y_b;
        tele_a[i] = {x_a, y_a};
        tele_b[i] = {x_b, y_b};
    }

    dist_ = abs(start_x - end_x) + abs(start_y - end_y);
    solve(0, tele_a, tele_b, 0, start);
    cout << dist_;

}
