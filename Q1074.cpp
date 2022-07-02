#include <bits/stdc++.h>
using namespace std;

int dimension, row, column;

int solve(int current_dimension, int x_start, int y_start){
    int total = 0;
    int next_dimension = current_dimension/2;
    //Counts which section
    int th = 0;
    for(int y = 1; y <= 2; y++){
        for(int x = 1; x <= 2; x++){
            //Dividing into sections by start and end
            int next_y_start = ((y-1)*next_dimension) + y_start;
            int next_x_start = ((x-1)*next_dimension) + x_start;

            int next_y_end = ((y*next_dimension)-1) + y_start;
            int next_x_end = ((x*next_dimension)-1) + x_start;
            
            //If row and column found, return current value
            if(next_y_start == row && next_x_start == column){
                return (th) * pow(next_dimension, 2);
            }
            else if(next_y_start <= row && next_y_end >= row && next_x_start <= column && next_x_end >= column){
                total += solve(next_dimension, next_x_start, next_y_start) + ((th) * pow(next_dimension, 2));
            }
            th++;
        }
    }

    return total;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n >> row >> column;

    dimension = pow(2, n);
    cout << solve(dimension, 0, 0);

}
