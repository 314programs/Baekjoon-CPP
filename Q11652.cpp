#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    vector<long long> num_list(n);
    for(int i = 0; i < n; i++){
        cin >> num_list[i];
    }
    sort(num_list.begin(), num_list.end());

    int counter = 0;
    long long current_num = 0;

    long long cur = pow(2, 62) + 1;
    int cnt = 0;

    for(int i = 0; i < n; i++){
        if(num_list[i] != cur){
            if(cnt > counter){
                current_num = num_list[i-1];
                counter = cnt;
            }
            cnt = 1;
            cur = num_list[i];
        }
        else{
            cnt++;
        }
    }

    if(cnt > counter){
        current_num = num_list[n-1];
        counter = cnt;
    }
    cout << current_num;
}
