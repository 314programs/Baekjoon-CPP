#include <bits/stdc++.h>
using namespace std;

int list_len, sections;

//Function to calculate if maximum score in a section can be made
bool calc(int max_min, vector<int> & a){
    int section_count = 1;
    int min_ = 10000, max_ = 0;
    for(int i = 0; i < list_len; i++){
        min_ = min(min_, a[i]);
        max_ = max(max_, a[i]);
        if(max_ - min_ > max_min){
            min_ = a[i];
            max_ = a[i];
            section_count++;
        }
    }
    //If the section count is lower, it means it still can be divided to match the number of sections
    if(section_count <= sections) return true;
    else return false;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> list_len >> sections;

    vector<int> num_list(list_len);
    int total = 0;
    for(int i = 0; i < list_len; i++){
        cin >> num_list[i];
        total += num_list[i];
    }

    int left = 0, right = total;
    int ans = 0;
    //Mid = maximum score in a section
    while(left <= right){
        int mid = (left+right)/2;
        if(calc(mid, num_list) == false){
            left = mid + 1;
        }
        else{
            ans = mid;
            right = mid - 1;
        }
    }
    cout << ans;
}
