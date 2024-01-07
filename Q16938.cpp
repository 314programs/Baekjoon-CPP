#include <bits/stdc++.h>
using namespace std;

long long question_num, lower_sum, higher_sum, min_dif;
int ans = 0;
int visited[15];

//Make all combinations
void solve(vector<long long> & questions, int len_, long long sum_, long long min_, long long max_, int last){
    if(len_ >= 2){
        if(sum_ >= lower_sum && sum_ <= higher_sum && max_ - min_ >= min_dif) ans++;
        if(sum_ > higher_sum) return;
    }
    if(len_ == question_num){
        return;
    }

    for(int i = 0; i < question_num; i++){
        //i > last is to avoid repetition
        if(visited[i] == 0 && i > last){
            visited[i] = 1;
            solve(questions, len_+1, sum_ + questions[i], min(min_, questions[i]), max(max_, questions[i]), i);
            visited[i] = 0;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> question_num >> lower_sum >> higher_sum >> min_dif;

    vector<long long> questions(question_num);
    for(int i = 0; i < question_num; i++){
        cin >> questions[i];
    }

    memset(visited, 0, sizeof(visited));
    solve(questions, 0, 0, 1000001, -1, -1);
    cout << ans;
}
