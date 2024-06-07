//Doing bronze questions due to exam + bad condition
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int a, b;
    int c, d;
    cin >> a >> b >> c >> d;

    cout << min(a + d, b + c);

}
