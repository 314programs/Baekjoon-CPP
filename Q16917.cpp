#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int sauce_p, fried_p, half_p;
    int sauce_num, fried_num;

    cin >> sauce_p >> fried_p >> half_p >> sauce_num >> fried_num;
    half_p *= 2;
    int price = 0;
    
    //Purchase half chicken first
    if(sauce_num > 0 && fried_num > 0 && half_p < (sauce_p + fried_p)){
        int min_ = min(sauce_num, fried_num);
        price += min_ * half_p;

        sauce_num -= min_;
        fried_num -= min_;
    }
    
    //If its more profitable to buy half chicken for the rest.
    if(sauce_num > 0){
        price += min(sauce_p * sauce_num, sauce_num * half_p);
    }
    if(fried_num > 0){
        price += min(fried_p * fried_num, fried_num * half_p);
    }

    cout << price;

}
