//Difficult to find pattern... this one is actually an ad hoc
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

int a[1000][1000];

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    memset(a, 0, sizeof(a));
   
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    
    //Found out pattern of the question
    //Pattern has to be repeated per 2 columns or rows
    //Find which one is max and print
    vector<vector<int>> vertical(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            vertical[i%2][j] += a[i][j];
        }
    }

    vector<vector<int>> horizontal(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            horizontal[j%2][i] += a[i][j];
        }
    }

    int verti_ans = 0;
    for(int i = 0; i < n; i++){
        verti_ans += max(vertical[0][i], vertical[1][i]); 
    }

    int hori_ans = 0;
    for(int i = 0; i < n; i++){
        hori_ans += max(horizontal[0][i], horizontal[1][i]); 
    }
    cout << max(hori_ans, verti_ans);

}
