#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int people;
    cin >> people;

    vector<int> time_taken(people);

    for(int i = 0; i < people; i++){
        cin >> time_taken[i];
    }

    sort(time_taken.begin(), time_taken.end());

    int ans = 0;
    int wait = 0;
    for(int i = 0; i < people; i++){
        ans += time_taken[i] + wait;
        wait += time_taken[i];
    }
    cout << ans;

}
