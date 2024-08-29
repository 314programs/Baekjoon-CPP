#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    int counter[10001];
    memset(counter, 0, sizeof(counter));

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        counter[temp]++;
    }

    for(int i = 0; i <= 10000; i++){
        for(int j = 0; j < counter[i]; j++){
            cout << i << "\n";
        }
    }

}
