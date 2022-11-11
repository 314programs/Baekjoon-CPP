//I thought it was simulation initially...
//Should practice more ad hoc as I am not good at it

#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

int n;
int a[10][10];
bool ans[10];
bool color[10];

//c1 covers c2
bool overlap(int c1, int c2){
    int left = n, right = 0, top = n, bottom = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == c2){
                left = min(left, j);
                right = max(right, j);
                top = min(top, i);
                bottom = max(bottom, i);
            }
        }
    }
    
    //Returns false if c1 overlaps c2
    for(int i = top; i <= bottom; i++){
        for(int j = left; j <= right; j++){
            if(a[i][j] == c1) return false;
        }
    }
    return true;
}
 
int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    memset(ans, false, sizeof(ans));
    memset(color, false, sizeof(color));

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            a[i][j] = s[j]-'0';
            ans[a[i][j]] = true;
            color[a[i][j]] = true;
        }
    }
    ans[0] = false;

    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            if(color[i] && color[j] && i != j){
                //If i overlaps other color, then that means it cannot be the first
                if(overlap(i, j) == false){
                    ans[i] = false;
                }
            }
        }
    }

    int res = 0;
    for(auto ch: ans){
        if(ch) res++;
    }
    cout << res;

}
