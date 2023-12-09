#include <bits/stdc++.h>
using namespace std;


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int height, width;
    cin >> height >> width;
    cin.ignore();

    for(int i = 0; i < height; i++){
        string temp;
        getline(cin, temp);
        reverse(temp.begin(), temp.end());
        cout << temp << "\n";
    }

}
