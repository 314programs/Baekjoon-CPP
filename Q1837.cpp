#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define int long long

void setIO(string s = ""){
	if(s == "") return;
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}

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

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	string p;
	int k;
	cin >> p >> k;

	int sieve[1000001];
    vector<int> primes;

    memset(sieve, 0, sizeof(sieve));
    sieve[0] = 1;
    sieve[1] = 1;

    for(int i = 2; i <= 1000000; i++){
        if(sieve[i] == 0){
            primes.push_back(i);
            for(int j = i + i; j <= 1000000; j += i){
                sieve[j] = 1;
            }
        }
    }

	string ans = "GOOD";
	int div = -1;
	for(auto i: primes){
		if(divideLargeNumber(p, to_string(i)) == 0 && i < k){
			ans = "BAD";
			div = i;
			break;
		}
	}
	cout << ans;
	if(ans != "GOOD"){
		cout << " " << div;
	}

}
