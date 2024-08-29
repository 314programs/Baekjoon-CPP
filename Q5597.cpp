//Test ended, time to celebrate
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int check[31];
    memset(check, 0, sizeof(check));

    for(int i = 0; i < 28; i++){
        int temp;
        cin >> temp;
        check[temp] = 1;
    }

    for(int i = 1; i <= 30; i++){
        if(check[i] == 0) cout << i << "\n";
    }


}
