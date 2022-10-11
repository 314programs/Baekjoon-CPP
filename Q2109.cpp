#include <bits/stdc++.h>
using namespace std;

struct meet{
    int days;
    int value;
};

bool compare(meet u, meet v){
    return u.days > v.days;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int meeting_count;
    cin >> meeting_count;

    vector<meet> meetings;
    for(int i = 0; i < meeting_count; i++){
        int d_, v_;
        cin >> v_ >> d_;
        meetings.push_back({d_, v_});
    }
    
    //Sort biggest date to smallest
    sort(meetings.begin(), meetings.end(), compare);
    long long ans = 0;
    
    priority_queue<int> q_;
    int idx = 0;
    
    //Reverse loop, since the day of meetings have to be below or equal to current date(i)
    //So even if it is in the q_, it is still valid since the date is going backwards
    for(int i = 10000; i > 0; i--){
        //If the idx is not over the count && if the meeting in the index is on the current day
        while(idx < meeting_count && meetings[idx].days == i){
            q_.push(meetings[idx].value);
            idx++;
        }
        //Will take out the biggest value
        if(!q_.empty()){
            ans += q_.top();
            q_.pop();
        }
    }
    
    cout << ans;
}
