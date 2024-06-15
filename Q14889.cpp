//40ms
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

//36ms
#include <bits/stdc++.h>
using namespace std;

int graph[20][20];
int people_count;

int score(vector<int> & team){
    int sum_ = 0;
    for(int i = 0; i < people_count/2; i++){
        for(int j = 0; j < people_count/2; j++){
            sum_ += graph[team[i]][team[j]];
        }
    }
    return sum_;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> people_count;
    for(int i = 0; i < people_count; i++){
        for(int j = 0; j < people_count; j++){
            cin >> graph[i][j];
        }
    }

    //Team 0 and 1 instead of 1 and 2
    vector<int> people(people_count/2);
    for(int i = 0; i < people_count/2; i++){
        people.push_back(1);
    }

    int ans = 2147483647;

    do{
        vector<int> first_team;
        vector<int> second_team;

        for(int i = 0; i < people_count; i++){
            if(people[i] == 0) first_team.push_back(i);
            if(people[i] == 1) second_team.push_back(i);
        }

        ans = min(ans, abs(score(first_team) - score(second_team)));

    } while(next_permutation(people.begin(), people.end()));

    cout << ans;

}



