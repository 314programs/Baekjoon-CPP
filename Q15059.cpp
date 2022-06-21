//Korea trip still going
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int ava_C, ava_B, ava_P;
    int want_C, want_B, want_P;

    cin >> ava_C >> ava_B >> ava_P;
    cin >> want_C >> want_B >> want_P;

    cout << max(want_C - ava_C, 0) + max(want_B - ava_B, 0) + max(want_P - ava_P, 0);

}
