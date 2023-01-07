#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> num_list(n);
    for(int i = 0; i < n; i++){
        cin >> num_list[i];
    }

    sort(num_list.begin(), num_list.end());
    for(auto ch: num_list){
        cout << ch << "\n";
    }

}
