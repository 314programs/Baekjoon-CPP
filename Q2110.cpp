#include <bits/stdc++.h>
using namespace std;

int check(int dist, vector<int> & houses){
    //Returns number of routers that can be placed
    int last = houses[0];
    int counter = 1;
    for(auto ch: houses){
        if(ch - last >= dist){
            counter++;
            last = ch;
        }
    }
    return counter;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    //Input and sorting
    int house_num, router_num;
    cin >> house_num >> router_num;

    vector<int> houses(house_num);
    for(int i = 0; i < house_num; i++){
        cin >> houses[i];
    }
    sort(houses.begin(), houses.end());
     
    //Max distance that matches C will be found in binary sort
    //Min and max distance is set
    int left = 1, right = houses[house_num-1] - houses[0];
    int ans = 0;
    while(left <= right){
        //Current distance = middle
        int current_dist = (left+right)/2;
        int how_many = check(current_dist, houses);
        if(how_many < router_num){
            right = current_dist - 1;
        }
        else{
            ans = current_dist;
            left = current_dist + 1;
        }
    }
    cout << ans;
}
