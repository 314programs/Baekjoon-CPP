#include <bits/stdc++.h>
using namespace std;

struct record{
    int day;
    string name, change;
};

bool compare(record &u, record &v){
    return u.day < v.day;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    int Bessie = 7;
    int Elsie = 7;
    int Mildred = 7;

    vector<record> cows(n);
    for(int i = 0; i < n; i++){
        int d;
        string n, c;
        cin >> d >> n >> c;
        cows[i] = {d, n, c};
    }

    sort(cows.begin(), cows.end(), compare);
    
    //Could have optimised, but no need as n is small
    vector<string> display(3);
    display = {"B", "E", "M"};
    int maximum = 7;
    int change = 0;

    for(record r: cows){
        int add = r.change[1]-'0';
        if(r.change[0] == '-') add *= -1;

        if(r.name == "Bessie") Bessie += add;
        else if(r.name == "Elsie") Elsie += add;
        else Mildred += add;

        vector<string> current_d;
        int cur_max = max({Bessie, Elsie, Mildred});

        if(Bessie == cur_max) current_d.push_back("B");
        if(Elsie == cur_max) current_d.push_back("E");
        if(Mildred == cur_max) current_d.push_back("M");

        if(current_d != display) change++;
        display = current_d;
    }

    cout << change;

}
