#include <bits/stdc++.h>
using namespace std;

//time, type of milk drank, by which person
bool a[101][51][51];

//time of getting sick, person getting sick
bool s[101][51];

//number of ppl who drank the milk
set<int> m[51];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int friend_cnt, milk_type, drink_cnt, sick_cnt;
    cin >> friend_cnt >> milk_type >> drink_cnt >> sick_cnt;

    memset(s, false, sizeof(s));

    for(int i = 0; i < drink_cnt; i++){
        int person, milk, time;
        cin >> person >> milk >> time;
        m[milk].insert(person);
        a[time][milk][person] = true;
    }

    for(int i = 0; i < sick_cnt; i++){
        int person, time;
        cin >> person >> time;
        s[time][person] = true;
    }

    int ans = 0;
    //For each type of milk
    for(int i = 1; i <= milk_type; i++){
        
        //Keeps track of milk drank by which person
        bool p[51];
        memset(p, false, sizeof(p));
        bool cannot = false;
        int check = 0;

        //For every possible time
        for(int j = 1; j <= 100; j++){
            //For every possible person
            for(int k = 1; k <= friend_cnt; k++){
                //Cannot be this milk because the person got sick before drinking
                if(s[j][k] == true && p[k] == false){
                    cannot = true;
                    break;
                }
                //1 person got sick after drinking
                if(s[j][k] == true && p[k] == true){
                    check += 1;
                }
                //Check person
                if(a[j][i][k] == true) p[k] = true;
            }
            if(cannot) break;
        }
        //If number of people got sick by this milk is equal to sick_cnt, it has to be the one that got bad
        if(check == sick_cnt){
            ans = max(ans, (int) m[i].size());
        }
    }

    cout << ans;

}
