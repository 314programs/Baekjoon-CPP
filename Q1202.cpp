#include <bits/stdc++.h>
using namespace std;

//Making struct makes lifes easier
struct jewel{
    int weight;
    int value;
};

//For sorting
bool compare(jewel u, jewel v){
    return u.value > v.value;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int jewel_num, bag_num;
    cin >> jewel_num >> bag_num;

    vector<jewel> jewels;
    multiset<int> bags;
    
    //Input
    for(int i = 0; i < jewel_num; i++){
        int w_, v_;
        cin >> w_ >> v_;
        jewels.push_back({w_, v_});
    }

    for(int i = 0; i < bag_num; i++){
        int temp;
        cin >> temp;
        bags.insert(temp);
    }
    
    //Sorting by highest value first
    sort(jewels.begin(), jewels.end(), compare);
    long long ans = 0;

    for(jewel j : jewels){
        //Locating bag that is equal or bigger then the weight of current jewel, it will always be the smallest value if located
        multiset<int> :: iterator current = bags.lower_bound(j.weight);
        //If located, add answer and delete the bag as it is used
        if(current != bags.end()){
            ans += j.value;
            bags.erase(current);
        }
    }
    cout << ans;

}
