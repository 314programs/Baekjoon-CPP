#include <bits/stdc++.h>
using namespace std;

struct cow{
    int arrive_t, take_t;
};

bool compare(cow u, cow v){
    if(u.arrive_t == v.arrive_t){
        return u.take_t < v.take_t;
    }
    return u.arrive_t < v.arrive_t;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    vector<cow> c(n);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        c[i] = {a, b};
    }

    sort(c.begin(), c.end(), compare);

    int current_time = 0;
    for(auto ch: c){
        if(current_time < ch.arrive_t){
            current_time = ch.arrive_t;
        }
        current_time += ch.take_t;
    }
    cout << current_time;

}
