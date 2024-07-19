//Orientation day
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int month, day;
    cin >> month >> day;

    if(month == 2 && day == 18){
        cout << "Special";
    }
    else if(month == 2 && day > 18){
        cout << "After";
    }
    else if(month > 2){
        cout << "After";
    }
    else{
        cout << "Before";
    }

}
