#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

double c_x, c_y, c_z;

//Calculates distance
double calc(double a_x, double a_y, double a_z){
    return (double) sqrt(((a_x - c_x)*(a_x - c_x)) + ((a_y - c_y)*(a_y - c_y)) + ((a_z - c_z)*(a_z - c_z)));
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    double a_x, a_y, a_z;
    double b_x, b_y, b_z;

    cin >> a_x >> a_y >> a_z;
    cin >> b_x >> b_y >> b_z;
    cin >> c_x >> c_y >> c_z;
     
    //Ternary search
    while(true){
        double l_x = a_x + (b_x - a_x)/3.0, l_y = a_y + (b_y - a_y)/3.0, l_z = a_z + (b_z - a_z)/3.0;
        double r_x = b_x - (b_x - a_x)/3.0, r_y = b_y - (b_y - a_y)/3.0, r_z = b_z - (b_z - a_z)/3.0;

        double left = calc(l_x, l_y, l_z);
        double right = calc(r_x, r_y, r_z);

        if(abs(left-right) < 1e-6){
            break;
        }

        if(left < right){
            b_x = r_x;
            b_y = r_y;
            b_z = r_z;
        }
        else{
            a_x = l_x;
            a_y = l_y;
            a_z = l_z;
        }
    }
    printf("%.6lf\n", calc((a_x + b_x)/2.0, (a_y + b_y)/2.0, (a_z + b_z)/2.0));
}
