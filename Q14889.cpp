#include <bits/stdc++.h>
using namespace std;

int dimension;
int people[20][20];
vector<int> first, second;
int difference;

void backtrack(int index_){
    if(index_ == dimension){
        if(first.size() != second.size()) return; 

        int team1 = 0, team2 = 0;

        for(int i = 0; i < dimension/2; i++){
            for(int j = 0; j < dimension/2; j++){
                if(i != j){
                    team1 += people[first[i]][first[j]];
                    team2 += people[second[i]][second[j]];
                }
            }
        }

        if(difference > abs(team1 - team2)){
            difference = abs(team1 - team2);
        }

        return;
    }

    first.push_back(index_);
    backtrack(index_ + 1);
    first.pop_back();

    second.push_back(index_);
    backtrack(index_ + 1);
    second.pop_back();

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> dimension;
    difference = 101;

    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            cin >> people[i][j];
        }
    }

    backtrack(0);
    cout << difference;
    
}

