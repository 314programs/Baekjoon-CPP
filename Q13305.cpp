//Greedy...
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    vector<ll> connection(n-1);
    vector<ll> city(n);
    //Buy until smaller price appears
    //If smaller price appears, switch to that price
    for(int i = 0; i < n-1; i++){
        cin >> connection[i];
    }
    for(int i = 0; i < n; i++){
        cin >> city[i];
    }

    ll cur_cost = city[0];
    ll cur_path = 0;
    ll total = 0;
    for(int i = 0; i < n-1; i++){
        if(cur_cost <= city[i]){
            cur_path += connection[i];
        }
        else{
            total += cur_path * cur_cost;
            cur_cost = city[i];
            cur_path = connection[i];
        }
    }
    total += cur_path * cur_cost;
    cout << total;

}
