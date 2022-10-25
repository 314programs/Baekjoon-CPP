#include <bits/stdc++.h>
using namespace std;

//Kinda complicated to store name and second last place...
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string cows[7] = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
    map<string, int> m;

    for(int i = 0; i < 7; i++){
        m[cows[i]] = 0;
    }

    int n;
    cin >> n;

    while(n--){
        string name;
        int amount;
        cin >> name >> amount;
        m[name] += amount;
    }

    set<int> s;
    vector<int> amount;
    
    //Sorting to find second last
    for(int i = 0; i < 7; i++){
        if(s.count(m[cows[i]]) == 0){
            s.insert(m[cows[i]]);
            amount.push_back(m[cows[i]]);
        }
    }
    sort(amount.begin(), amount.end());

    string ans = "Tie";
    int min_val;
    if(amount.size() != 1){
        min_val = amount[1];
    }

    int min_cnt = 0;
    vector<string> second_last;
    for(int i = 0; i < 7; i++){
        if(m[cows[i]] == min_val){
            min_cnt++;
            second_last.push_back(cows[i]);
        }
    }

    if(second_last.size() == 1) ans = second_last[0];
    cout << ans;

}
