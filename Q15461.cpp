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

struct Log{
	int day, id, change;
};
 
int32_t main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);
 
    setIO("measurement");

    int n, g;
	cin >> n >> g;

	vector<Log> a(n);
	map<int, int> cows;
	for(int i = 0; i < n; i++){
		int d, id;
		string c;
		cin >> d >> id >> c;

		int temp;
		if(c[0] == '+'){
			temp = stoll(c.substr(1, c.length()-1));
		}
		else{
			temp = -stoll(c.substr(1, c.length()-1));
		}
		a[i] = {d, id, temp};
		cows[a[i].id] = g;
	}
	sort(a.begin(), a.end(), [&](Log &u, Log &v){
		return u.day < v.day;
	});

	map<int, int> milk{{g, n}};
	int change = 0;

	for(auto ch: a){
		int milk_amt = cows[ch.id];
		bool was_top = (milk_amt == milk.rbegin() -> first);
		int prev_cnt = milk[milk_amt];

		milk[milk_amt]--;
		if(milk[milk_amt] == 0){
			milk.erase(milk_amt);
		}

		milk_amt += ch.change;
		cows[ch.id] = milk_amt;
		milk[milk_amt]++;

		bool is_top = (milk_amt == milk.rbegin() -> first);
		int cur_cnt = milk[milk_amt];
		if(was_top){
			if(!(is_top && prev_cnt == cur_cnt)){
				change++;
			}
		}
		else if(is_top){
			change++;
		}
	}
	cout << change;

}
