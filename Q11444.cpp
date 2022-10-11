#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<long long>> matrix;
long long mod = 1000000007;

matrix operator *(const matrix &a, const matrix &b){
    matrix ans(2, vector<long long>(2));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            ans[i][j] = 0;
            for(int k = 0; k < 2; k++){
                ans[i][j] += a[i][k] * b[k][j];
            }
            ans[i][j] %= mod;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    long long num;
    cin >> num;
    num -= 1;
    
    //This is a 1 in matrix multiplication
    matrix ans = {{1,0},{0,1}};
    matrix a = {{1,1},{1,0}};
    
    //This is easier then making a function!
    while(num > 0){
        if(num%2 == 1){
            ans = ans * a;
        }
        num /= 2;
        a = a*a;
    }

    cout << ans[0][0];

}
