#include <bits/stdc++.h>
using namespace std;

struct point{
    int x, y;
};

bool compare(point u, point v){
    if(u.x == v.x){
        return u.y < v.y;
    }
    return u.x < v.x;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    vector<point> num_list(n);
    for(int i = 0; i < n; i++){
        int x_, y_;
        cin >> x_ >> y_;
        num_list[i] = {x_, y_};
    }

    sort(num_list.begin(), num_list.end(), compare);
    for(auto ch: num_list){
        cout << ch.x << " " << ch.y << "\n";
    }

}
