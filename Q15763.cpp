#include <bits/stdc++.h>
using namespace std;

string graph[3];
int a_cnt;
int b_cnt;

//Represent a and b used as numbers
//If a and b is used together, it should not be 3 or 6
int check(int i, int j, char a, char b){
    if(graph[i][j] == a || graph[i][j] == b){
        if(graph[i][j] == a) return 1;
        if(graph[i][j] == b) return 2;
    }
    return -1000;
}

int solve(char a, char b, int calc){
    int res = 0;
    
    //Horizontal and vertical
    for(int i = 0; i < 3; i++){
        int t1 = check(i, 0, a, b) + check(i, 1, a, b) + check(i, 2, a, b);
        if(t1 > 0){
            if(calc == 1 && t1 >= 3 && t1 <= 6)  res++;
            else if(calc == 2 && t1 > 3 && t1 < 6) res++;
        }

        int t2 = check(0, i, a, b) + check(1, i, a, b) + check(2, i, a, b);
        if(t2 > 0){
            if(calc == 1 && t2 >= 3 && t2 <= 6) res++;
            else if(calc == 2 && t2 > 3 && t2 < 6) res++;
        }
    }
    
    //Diagonal
    int t3 = check(0, 0, a, b) + check(1, 1, a, b) + check(2, 2, a, b);
    if(t3 > 0){
        if(calc == 1 && t3 >= 3 && t3 <= 6)  res++;
        else if(calc == 2 && t3 > 3 && t3 < 6) res++;
    }

    int t4 = check(0, 2, a, b) + check(1, 1, a, b) + check(2, 0, a, b);
    if(t4 > 0){
        if(calc == 1 && t4 >= 3 && t4 <= 6) res++;
        else if(calc == 2 && t4 > 3 && t4 < 6) res++;
    }

    if(res != 0) return 1;
    return 0;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    
    map<int, int> m;
    for(int i = 0; i <= 25; i++){
        m[i] = 0;
    }
    
    for(int i = 0; i < 3; i++){
        cin >> graph[i];
        for(auto ch: graph[i]){
            m[ch-'A'] += 1;
        }
    }

    int single_win = 0;
    int double_win = 0;
    
    //Combinations
    for(int i = 0; i <= 25; i++){
        if(m[i] != 0){
            single_win += solve(i+'A', i+'A', 1);
        }
        for(int j = i+1; j <= 25; j++){
            if(m[i] != 0 && m[j] != 0){
                double_win += solve(i+'A', j+'A', 2);
            }
        }
    }

    cout << single_win << "\n" << double_win;

}
