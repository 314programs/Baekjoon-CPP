#include <bits/stdc++.h>
using namespace std;

string s;
//Length, first previous, second previous, l included?
long long DP[101][3][3][2];
//L, mo, ja
int multi[3] = {0, 5, 20};

//1 = mo, 2 = ja
int what(char ch){
    if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
        return 1;
    }
    return 2;
}

long long solve(int idx, int p1, int p2, int l){
    if(idx == s.length()){
        return l;
    }
    //Memoization
    long long &ans = DP[idx][p1][p2][l];
    if(ans != -1) return ans;
    ans = 0;
    
    //Not an empty space
    if(s[idx] != '_'){
        int current = what(s[idx]);
        if(p1 == p2 && current == p2) return 0;
        ans += solve(idx+1, p2, current, (l | (s[idx] == 'L')));
        return ans;
    }
    //Empty space, put mo or ja
    for(int i = 1; i <= 2; i++){
        if(p1 == p2 && p2 == i) continue;
        ans += multi[i] * solve(idx+1, p2, i, l);
    }
    
    //Put l
    if(!(p1 == p2 && p2 == 2)) ans += solve(idx+1, p2, 2, 1);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    
    cin >> s;
    memset(DP, -1, sizeof(DP));
    cout << solve(0, 0, 0, 0);
    
}
