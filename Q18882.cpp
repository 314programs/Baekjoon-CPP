//This is a silver 3??? Needs to be silver 2 at least...
//My contribution turned it into a silver 2...
#include <bits/stdc++.h>
using namespace std;

int shake_x[251], shake_y[251];
int cow_cnt, n;
bool end_infect[101];

bool check_pos(int c, int k){
    bool infected[101] = {false};
    int shake_cnt[101] = {0};
    infected[c] = true;
    
    for(int i = 0; i <= 250; i++){
        int x = shake_x[i], y = shake_y[i];
        //x and y are cows that exist!
        if(x > 0){
            //Increase handshake number
            //If handshake number is smaller then k, infect
            if(infected[x]) shake_cnt[x]++;
            if(infected[y]) shake_cnt[y]++;
            if(infected[x] && shake_cnt[x] <= k) infected[y] = true;
            if(infected[y] && shake_cnt[y] <= k) infected[x] = true;
        }   
    }
    
    //Simulation should match the end result
    for(int i = 1; i <= cow_cnt; i++){
        if(end_infect[i] != infected[i]){
            return false;
        }
    }
    return true;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string s;
    cin >> cow_cnt >> n;
    cin >> s;

    int possible = 0;
    int upper, lower;

    for (int i=1; i<=cow_cnt; i++){
        end_infect[i] = s[i-1]=='1';
    }
        
    for(int i = 0; i < n; i++){
        int t, a, b;
        cin >> t >> a >> b;
        //HOW DID I WRITE t as i
        //I spent 2 hours for this
        shake_x[t] = a;
        shake_y[t] = b;
    }

    bool K_val[252] = {false};
    bool pos_val[101] = {false};
    
    //251 is max value for k as it is used to calculate infinity
    for(int i = 1; i <= cow_cnt; i++){
        for(int K = 0; K <= 251; K++){
            //Checks possibility of each patient zero and K
            if(check_pos(i, K)){
                pos_val[i] = true; K_val[K] = true;
            }
        }
    }
    
    //In both increasing and decreasing order, find lower and upper K
    for(int K = 0; K <= 251; K++) if(K_val[K]) upper = K;
    for(int K = 251; K >= 0; K--) if(K_val[K]) lower = K;
  
    //For each possible patient zero
    for(int i = 1; i <= cow_cnt; i++) if(pos_val[i]) possible += 1;

    cout << possible << " " << lower << " ";
    if(upper == 251){
        cout << "Infinity";
    }
    else{
        cout << upper;
    }

}
