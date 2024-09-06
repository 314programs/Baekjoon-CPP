//Could not sleep today
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    float a, b;
    cin >> a >> b;

    float pi = 3.141592;

    cout << setprecision(6) << fixed << a*2 + 2 * b * pi;

}
