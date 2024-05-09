#include <bits/stdc++.h>
using namespace std;

int main(void){
    //Confused 8 with 10
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string num_8;
    cin >> num_8;

    long long result = 0;
    int size_ = num_8.size();

    if(size_%3 == 1){
        cout << num_8[0];
    }
    else if(size_%3 == 2){
        cout << (num_8[0]-'0')*2 + (num_8[1]-'0');
    }
    for(int i = size_%3; i < size_; i += 3){
        cout << (num_8[i]-'0')*4 + (num_8[i+1]-'0')*2 + (num_8[i+2]-'0');
    }

}
