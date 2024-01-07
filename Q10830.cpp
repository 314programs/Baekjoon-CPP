#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> matrix;
matrix operator * (const matrix &a, const matrix &b){
    //Multiplication between matrixes
    int n = a.size();
    matrix c(n, vector<int> (n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= 1000;
        }
    }
    return c;
}

matrix multi(int dimension, const matrix &a, long long power){
    if(power == 1){
        return a;
    }

    if(power%2 == 0){
        matrix temp = multi(dimension, a, power/2);
        return temp * temp;
    }
    else{
        matrix temp = multi(dimension, a, power-1);
        return temp * a;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int dimension;
    long long power;
    cin >> dimension >> power;

    matrix ans(dimension, vector<int> (dimension));
    matrix a(dimension, vector<int> (dimension));

    for(int y = 0; y < dimension; y++){
        for(int x = 0; x < dimension; x++){
            cin >> a[y][x];
        }
    }

    ans = multi(dimension, a, power);

    for(int y = 0; y < dimension; y++){
        for(int x = 0; x < dimension; x++){
            //Final %mod
            cout << ans[y][x]%1000 << " ";
        }
        cout << "\n";
    }

}
