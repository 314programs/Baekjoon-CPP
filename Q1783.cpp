#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int height, width;
    cin >> height >> width;

    if(height == 1){
        cout << 1;
    }
    else if(height == 2){
        cout << min(4, (width+1)/2);
    }
    else{
        if(width < 7){
            cout << min(4, width);
        }
        else{
            cout << width - 2;
        }
    }


}
