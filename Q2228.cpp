#include <bits/stdc++.h>
using namespace std;

//Numbers divided into sections, section count = total sum
int DP[101][51];
bool check[101][51];
int a[101];

int MIN = -2e9;

//Numbers included, section count
int solve(int n, int m){
    //Enough sections made
    if(m == 0) return 0;
    //Number is out of range
    if(n <= 0) return MIN;
    
    //Cannot return DP value when -1, because -1 is a possible value
    //Instead use check array
    if(check[n][m]) return DP[n][m];
    check[n][m] = true;

    int &ans = DP[n][m];
    //nth number not included
    ans = solve(n-1, m);
    int sum = 0;

    for(int k = n; k >= 1; k--){
        sum += a[k];
        //Make a section using nth number
        //k-2, because of space, m-1 cause 1 section to be made is gone
        int temp = solve(k-2, m-1) + sum;
        ans = max(ans, temp);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    memset(check, false, sizeof(check));
    cout << solve(n, m);

}
