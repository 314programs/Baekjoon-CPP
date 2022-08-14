#include <bits/stdc++.h>
using namespace std;

int CCW(long long  x1, long long  y1, long long  x2, long long  y2, long long  x3, long long  y3){
    long long ans = x1*y2 + x2*y3 + x3*y1;
    ans -= y1*x2 + y2*x3 + y3*x1;
    if(ans == 0) return 0;
    else if(ans > 0) return 1;
    else return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    //Find if they intersect using CCW
    long long x1, y1, x2, y2;
    long long  x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    int temp1 = CCW(x1, y1, x2, y2, x3, y3) * CCW(x1, y1, x2, y2, x4, y4);
    int temp2 = CCW(x3, y3, x4, y4, x1, y1) * CCW(x3, y3, x4, y4, x2, y2);
    
    //Since they also intersect when just touching, temp <= 0
    //There are some exceptions to this case, which this if statement takes care of
    if(temp1 == 0 && temp2 == 0){
        pair<long long, long long> line1_min = min(make_pair(x1, y1), make_pair(x2, y2));
        pair<long long, long long> line1_max = max(make_pair(x1, y1), make_pair(x2, y2));
        pair<long long, long long> line2_min = min(make_pair(x3, y3), make_pair(x4, y4));
        pair<long long, long long> line2_max = max(make_pair(x3, y3), make_pair(x4, y4));
      
        //If lines l1 and l2 are forming 1 line
        //p1 <= p4, p2 >= p3

        if(line2_min <= line1_max && line1_min <= line2_max){
            cout << 1;
        }
        else{
            cout << 0;
        }

    }
    else if(temp1 <= 0 && temp2 <= 0){
        cout << 1;
    }
    else{
        cout << 0;
    }

}
