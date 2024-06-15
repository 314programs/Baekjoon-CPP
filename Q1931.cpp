#include <bits/stdc++.h>
using namespace std;

struct meeting{
    int start;
    int end;
};

bool compare(const meeting &u, const meeting &v){
    if(u.end == v.end){
        return u.start < v.start;
    }
    else{
        return u.end < v.end;
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int meetings;
    cin >> meetings;
    vector<meeting> meets(meetings);

    for(int i = 0; i < meetings; i++){
        cin >> meets[i].start >> meets[i].end;
    }

    sort(meets.begin(), meets.end(), compare);
    int ans = 0;
    int now = 0;

    for(int i = 0; i < meetings; i++){
        if(meets[i].start >= now){
            ans += 1;
            now = meets[i].end;
        }
    }
    cout << ans;

}
