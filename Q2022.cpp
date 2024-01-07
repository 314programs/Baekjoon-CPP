#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    double x, y, c;
    cin >> x >> y >> c;

    double mid;
    double left = 0, right = max(x, y);
    while(abs(right - left) > 1e-6){
        mid = (left + right)/2.0;
        double h1 = sqrt((x*x)-(mid*mid));
        double h2 = sqrt((y*y)-(mid*mid));
        double h = (h1 * h2)/(h1 + h2);

        if(h > c){
            left = mid;
        }
        else{
            right = mid;
        }
    }
    printf("%.3lf", mid);

}
