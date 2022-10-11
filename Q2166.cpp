//Divide the shape into triangles
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int point_cnt;
    cin >> point_cnt;

    vector<long long> x_coord(point_cnt+1);
    vector<long long> y_coord(point_cnt+1);
    
    //Using CCW algorithm here to calculate the area
    for(int i = 0; i < point_cnt; i++){
        cin >> x_coord[i] >> y_coord[i];
    }
    x_coord[point_cnt] = x_coord[0];
    y_coord[point_cnt] = y_coord[0];

    long long add = 0;
    for(int i = 0; i < point_cnt; i++){
        add += x_coord[i] * y_coord[i+1];
    }
    long long subtract = 0;
    for(int i = 0; i < point_cnt; i++){ 
        subtract += y_coord[i] * x_coord[i+1];
    }
    
    //Times it by 0.5 to make all the values triangles
    double ans = abs(add - subtract) * 0.5;
    cout << fixed << setprecision(1) << ans << " ";

}
