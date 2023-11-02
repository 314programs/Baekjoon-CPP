#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int limit, speed;
    cin >> limit >> speed;

    if(speed <= limit){
        cout << "Congratulations, you are within the speed limit!";
    }
    else if(speed - limit <= 20){
        cout << "You are speeding and your fine is $100.";
    }
    else if(speed - limit <= 30){
        cout << "You are speeding and your fine is $270.";
    }
    else{
        cout << "You are speeding and your fine is $500.";
    }

}
