#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
	
    int a, b, c;
    cin >> a >> b >> c;

    if(a == b && b == c){
        cout << 10000 + (a * 1000);
    }
    else if(a == b){
        cout << 1000 + (a * 100);
    }
    else if(b == c){
        cout << 1000 + (b * 100);
    }
    else if(c == a){
        cout << 1000 + (c * 100);
    }
    else{
        cout << 100 * max(max(a, b), c);
    }

}
