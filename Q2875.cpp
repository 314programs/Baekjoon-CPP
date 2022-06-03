#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int girl, boy, intern;
    cin >> girl >> boy >> intern;

    while(intern--){
        if(girl/2 >= boy) girl--;
        else boy--;
    }

    cout << min(girl/2, boy);

}
