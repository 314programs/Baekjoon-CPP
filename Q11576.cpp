//Look back later, still confused about conversions
#include <bits/stdc++.h>
using namespace std;

void convert(int num, int base){
    if(num == 0){
        return;
    }
    convert(num/base, base);
    cout << num%base << " ";
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int a, b;
    cin >> a >> b;

    int n;
    cin >> n;

    int ans = 0;

    while(n--){
        int x;
        cin >> x;
        ans = ans * a + x;
    }

    convert(ans, b);

}
