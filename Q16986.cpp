//The most confusing question I have ever saw
//I never want to experience this again
#include <bits/stdc++.h>
using namespace std;

int match_result[10][10];
int moveset_num, wins_needed;
//Stores round per people
int people[3][20];
int ans = 0;

int wins[3];
int r[3];

void solve(int a, int b){
    if(wins[0] == wins_needed && wins[1] < wins_needed && wins[2] < wins_needed){
        ans = 1;
        return;
    }
    if(r[0] >= moveset_num || r[1] >= 20 || r[2] >= 20){
        return;
    }

    //A wins
    if(match_result[people[a][r[a]]][people[b][r[b]]] == 2){
        wins[a]++; r[a]++; r[b]++;
        solve(a, 3 - a - b);
    }
    //Draw... latest wins
    else if(match_result[people[a][r[a]]][people[b][r[b]]] == 1){
        int temp = max(b, a);
        wins[temp]++; r[a]++; r[b]++;
        solve(temp, 3 - a - b);
    }
    //B wins
    else if(match_result[people[a][r[a]]][people[b][r[b]]] == 0){
        wins[b]++; r[a]++; r[b]++;
        solve(b, 3 - a - b);
    }

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> moveset_num >> wins_needed;
    
    //Input
    memset(match_result, 0, sizeof(match_result));
    for(int i = 1; i <= moveset_num; i++){
        for(int j = 1; j <= moveset_num; j++){
            cin >> match_result[i][j];
        }
    }

    for(int i = 1; i < 3; i++){
        for(int j = 0; j < 20; j++){
            cin >> people[i][j];
        }
    }
    
    //All moves need to be used so permutation can be used
    for(int i = 1; i <= moveset_num; i++) people[0][i-1] = i;
    do{
        memset(wins, 0, sizeof(wins));
        memset(r, 0, sizeof(r));
        solve(0, 1);
    }
    while(next_permutation(people[0], people[0] + moveset_num));

    cout << ans;
}
