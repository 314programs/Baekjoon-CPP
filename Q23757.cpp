#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int gift_n, kid_n;
    cin >> gift_n >> kid_n;

    priority_queue<int> pq;
    for(int i = 0; i < gift_n; i++){
        int num;
        cin >> num;
        pq.push(num);
    }

    vector<int> a(kid_n);
    for(int i = 0; i < kid_n; i++){
        cin >> a[i];
    }

    int can = 1;
    for(auto ch: a){
        int current = pq.top();
        pq.pop();
        if(current >= ch){
            current -= ch;
            pq.push(current);
        }
        else{
            can = 0;
            break;
        }
    }
    cout << can;

}
