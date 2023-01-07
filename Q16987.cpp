#include <bits/stdc++.h>
using namespace std;
int egg_num;

struct egg{
    int attack, health;
};

int solve(int right, vector<egg> & egg_list){
    if(right >= egg_num){
        int count_ = 0;
        for(auto ch: egg_list){
            if(ch.health <= 0) count_++;
        }
        return count_;
    }

    int ans = 0;
    for(int i = 0; i < egg_num; i++){
        int current_idx_health = egg_list[i].health;
        int right_health = egg_list[right].health;

        if(egg_list[right].health > 0 && egg_list[i].health > 0 && right != i){
            //Smash current egg
            egg_list[i].health -= egg_list[right].attack;
            egg_list[right].health -= egg_list[i].attack;
            ans = max(solve(right+1, egg_list), ans);
            //Undo smashing
            egg_list[i].health = current_idx_health;
            egg_list[right].health = right_health;
        }
    }
    //If nothing could be smashed
    if(ans == 0) ans = max(solve(right+1, egg_list), ans);
    return ans;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> egg_num;

    vector<egg> egg_list(egg_num);
    for(int i = 0; i < egg_num; i++){
        int h, a;
        cin >> h >> a;
        egg_list[i] = {a, h};
    }

    cout << solve(0, egg_list);

}
