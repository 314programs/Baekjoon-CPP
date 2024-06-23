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

bool sieve[1003003];


int32_t main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

	int n;
	cin >> n;
	memset(sieve, false, sizeof(sieve));
	vector<int> primes;

	const int max = 1003002;
	sieve[0] = true;
	sieve[1] = true;

	for(int i = 2; i <= max; i++){
		if(sieve[i] == false){
			primes.push_back(i);
			for(int j = i + i; j <= max; j += i){
				sieve[j] = true;
			}
		}
	}

	int idx = lower_bound(primes.begin(), primes.end(), n) - primes.begin();
	while(true){
		string cur = to_string(primes[idx++]);
		int len = cur.length();

		bool palindrome = true;
		for(int i = 0; i < len/2; i++){
			if(cur[i] != cur[len - 1 - i]){
				palindrome = false;
				break;
			}
		}

		if(palindrome){
			cout << cur;
			break;
		}
	}

}
