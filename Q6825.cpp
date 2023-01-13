#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    float w, h;
    cin >> w >> h;

    float bmi = w/(h*h);
    if(bmi > 25){
        cout << "Overweight";
    }
    else if(bmi < 18.5){
        cout << "Underweight";
    }
    else{
        cout << "Normal weight";
    }

}
