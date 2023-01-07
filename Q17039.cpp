//I heavily dislike ad-hoc, and i always need help

#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;

    vector<int> cow_list = {a, b, c};
    sort(cow_list.begin(), cow_list.end());
    
    //If they are already in consecutive order
    if(cow_list[0]+1 == cow_list[1] && cow_list[1]+1 == cow_list[2]){
        cout << "0\n";
    }
    //If there is a gap of 2 between 2 cows, which means that one can be squeezed in
    else if(cow_list[1] == cow_list[0]+2 || cow_list[2] == cow_list[1]+2){
        cout << "1\n";
    }
    //Make pair of cows have gap of 2, then squeeze one in
    else{
        cout << "2\n";
    }
    
    //Largest gap minus one to get empty spaces between 2 cows
    cout << max(cow_list[1]-cow_list[0], cow_list[2]-cow_list[1])-1;

}
