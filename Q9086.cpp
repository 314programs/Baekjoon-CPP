#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int testcase;
    cin >> testcase;
    cin.ignore();

    while(testcase--){
        string temp;
        getline(cin, temp);
        cout << temp.front() << temp.back() << "\n";
    }


}
