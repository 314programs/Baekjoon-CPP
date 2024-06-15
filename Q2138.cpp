#include <bits/stdc++.h>
using namespace std;
int length_;

//Converting function
void convert(vector<int> &a, int pos){
    for(int i = pos-1; i <= pos + 1; i++){
        if(0 <= i && i < length_){
            a[i] = !a[i];
        }
    }
}

//Checking if it is possible by using switches
pair<int, bool> go(vector<int> start, vector<int> &end){
    int ans = 0;
    for(int i = 0; i < length_ - 1; i++){
        if(start[i] != end[i]){
            convert(start, i+1);
            ans += 1;
        }
    }

    if(start == end){
        return make_pair(ans, true);
    }
    else{
        return make_pair(ans, false);
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> length_;
    cin.ignore();

    string temp;
    vector<int> start_(length_);
    vector<int> end_(length_);
    
    //Input
    getline(cin, temp);
    for(int i = 0; i < length_; i++) start_[i] = temp[i] - '0';

    getline(cin, temp);
    for(int i = 0; i < length_; i++) end_[i] = temp[i] - '0';
    
    //Test 2 methods, one without turning on first switch, one with turning on first switch
    pair<int, bool> ans1 = go(start_, end_);
    convert(start_, 0);
    pair<int, bool> ans2 = go(start_, end_);

    if(ans2.second) ans2.first += 1;
    
    //Find if its possible, if it is find the minimum amount of switches used
    if(ans1.second && ans2.second) cout << min(ans1.first, ans2.first);
    else if(ans1.second) cout << ans1.first;
    else if(ans2.second) cout << ans2.first;
    else cout << -1;

}
