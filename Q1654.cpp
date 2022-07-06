#include <bits/stdc++.h>
using namespace std;

long long calc(int cut_num, vector<int> & wires){
    long long total = 0;
    for(auto ch:wires){
        total += ch/cut_num;
    }
    return total;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int wire_num, wire_needed;
    cin >> wire_num >> wire_needed;

    vector<int> wires(wire_num);
    for(int i = 0; i < wire_num; i++){
        cin >> wires[i];
    }

    long long left = 0, right = 2147483647;
    long long ans = 0;
    while(left <= right){
        long long mid = (left+right)/2;
        long long current_wire = calc(mid, wires);
        if(current_wire < wire_needed){
            right = mid - 1;
        }
        else{
            ans = mid;
            left = mid + 1;
        }
    }
    cout << ans;

}
