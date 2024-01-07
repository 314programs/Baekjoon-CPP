#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000000000;

bool compare(pair<int, int> u, pair<int, int> v){
    if(u.first == v.first){
        return u.second > v.second;
    }
    else{
        return u.first < v.first;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> lines(n*2);
    for(int i = 0; i < n*2; i+=2){
        int a;
        char b;
        cin >> b >> a;
        if(b == 'G'){
            lines[i] = make_pair(a, 1);
            lines[i+1] = make_pair(MAX, -1);
        }
        else{
            lines[i] = make_pair(0, 1);
            lines[i+1] = make_pair(a, -1);
        }
    }

    sort(lines.begin(), lines.end(), compare);
    int ans = 0;
    int cnt = 0;

    int prev = -1;
    int temp = 0;

    for(auto &ch: lines){
        cnt += ch.second;
        if(ch.first == prev){
            if(ch.second == -1){
                temp += 1;
            }
        }
        else{
            temp = 0;
        }

        ans = max(cnt+temp, ans);
        prev = ch.first;
    }
    cout << n-ans;
}
