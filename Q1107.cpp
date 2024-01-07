#include <bits/stdc++.h>
using namespace std;

bool broken[10];

bool check(string buttons){
    for(auto ch: buttons){
        if(broken[ch-'0'] == true){
            return false;
        }
    }
    return true;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int wanted_channel;
    int current_channel = 100;

    int broken_buttons;
    int min_button = 1000001;
    memset(broken, false, sizeof(broken));

    cin >> wanted_channel;
    cin >> broken_buttons;
    while(broken_buttons--){
        int temp;
        cin >> temp;
        broken[temp] = true;
    }

    for(int i = 0; i <= 1000000; i++){
        if(check(to_string(i))){
            int num_button = abs(i - wanted_channel);
            num_button += to_string(i).length();
            min_button = min(min_button, num_button);
        }
    }
    cout << min(min_button, abs(current_channel - wanted_channel));
}
