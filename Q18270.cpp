#include <bits/stdc++.h>
using namespace std;

map<string, int> cow_m;
bool check[8][8] = {false};

//For each permutation, check if n number of booleans are matched
//Booleans represent cows being next to each other
bool possible(vector<string> &cows, int n){
    int cnt = 0;
    for(int i = 0; i < 7; i++){
        if(check[cow_m[cows[i]]][cow_m[cows[i+1]]]){
            cnt++;
        }
    }

    if(cnt == n) return true;
    return false;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    //Sort the list to make it alphabetical
    vector<string> cows(8);
    cows = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    sort(cows.begin(), cows.end());
    

    int n;
    for(int i = 0; i < 8; i++){
        cow_m[cows[i]] = i;
    }

    cin >> n;
    
    //Input was slightly confusing
    for(int j = 0; j < n; j++){
        string c1;
        cin >> c1;
        for(int i = 0; i < 4; i++){
            string temp;
            cin >> temp;
        }
        string c2;
        cin >> c2;
        //Besides a cow illustrated in a boolean
        check[cow_m[c1]][cow_m[c2]] = true;
        check[cow_m[c2]][cow_m[c1]] = true;
    }
    
    //Make permutation
    do{
        if(possible(cows, n)){
            for(auto ch: cows){
                cout << ch << "\n";
            }
            break;
        }
    }
    while(next_permutation(cows.begin(), cows.end()));


}
