#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    while(true){
        int stick_cnt;
        cin >> stick_cnt;

        if(stick_cnt == 0) break;

        vector<int> sticks(stick_cnt);
        for(int i = 0; i < stick_cnt; i++){
            cin >> sticks[i];
        }

        stack<int> s;
        long long ans = 0;
        
        //Find the longest increasing height and calculate area from there
        //Then remove the increasing sticks one by one and calculate the area
        //Stick infront of the stack will be bigger then the previous as ones that are less are removed
        for(int i = 0; i < stick_cnt; i++){
            while(!s.empty() && sticks[s.top()] > sticks[i]){
                long long height = sticks[s.top()];
                s.pop();
                long long width = i;
                if(!s.empty()) width = i - s.top() - 1;
                ans = max(ans, height * width);
            }
            s.push(i);
        }
        
        //Calculate area of the rest using similar method
        while(!s.empty()){
            long long height = sticks[s.top()];
            s.pop();
            long long width = stick_cnt;
            if(!s.empty()) width = stick_cnt - s.top() - 1;
            ans = max(ans, height * width);
        }

        cout << ans << "\n";

    }

}
