#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long

//Works for numbers equal or below 10^6
//If a number equal or below 10^N, change all 7s in the function to N

int divideLargeNumber(string number, string divisor){
	int idx = min((int)number.length(), (int)7);
	string cur_num = number.substr(0, idx);

	while(stoll(cur_num) > stoll(divisor)){
		cur_num = to_string(stoll(cur_num)%stoll(divisor));
		while(cur_num.length() < 7 && idx < number.length()){
			cur_num += number[idx];
			idx++;
		}
	}
	return stoi(cur_num);
}
