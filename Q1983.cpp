#include <bits/stdc++.h>
using namespace std;

//current column, upper number used, lower number used
int DP[401][401][401];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> a;
    vector<int> b;
  
    //Add +1 to both the list sizes to make life easier
    a.push_back(0);
    b.push_back(0);
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        if(num != 0) a.push_back(num);
    }
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        if(num != 0) b.push_back(num);
    }

    for(int k = 1; k <= n; k++){
        //Starts from 1 due to the 0s added at the start
        for(int j = 1; j <= a.size(); j++){
            for(int i = 1; i <= b.size(); i++){
                //Out of range
                if(j > k || i > k) continue;
                //Use both, new value added
                int cur = DP[k-1][j-1][i-1] + a[j]*b[i];

                //Use only bottom row
                if(i - 1 >= 0 && k-1 >= j){
                    cur = max(cur, DP[k-1][j][i-1]);
                }

                //Use only top row
                if(j - 1 >= 0 && k-1 >= i){
                    cur = max(cur, DP[k-1][j-1][i]);
                }
                DP[k][j][i] = cur;
            }
        }
    }

    cout << DP[n][a.size()-1][b.size()-1];

}
