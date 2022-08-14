#include <bits/stdc++.h>
using namespace std;

int CCW(int x1, int y1, int x2, int y2, int x3, int y3){
    int temp = x1*y2 + x2*y3 + x3*y1;
    temp -= x2*y1 + x3*y2 + x1*y3;
    if(temp == 0) return 0;
    else if(temp < 0) return -1;
    else return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    cout << CCW(x1, y1, x2, y2, x3, y3);

}
