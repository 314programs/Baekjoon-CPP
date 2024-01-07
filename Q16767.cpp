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

struct cow{
	int senior, arrive, time;
};

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	setIO("");

	int n;
	cin >> n;

	vector<cow> a(n);
	for(int i = 0 ; i < n; i++){
		cin >> a[i].arrive >> a[i].time;
		a[i].senior = i;
	}
	sort(a.begin(), a.end(), [&](cow &u, cow &v){
		if(u.arrive == v.arrive){
			return u.senior < v.senior;
		}
		return u.arrive < v.arrive;
	});

	int ans = 0;
	//waiting list
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	int end = 0;

	for(auto ch: a){
		int fin = ch.arrive + ch.time;
		int arrive = ch.arrive;

		while(!pq.empty() && arrive > end){
			auto cur = pq.top();
			pq.pop();

			ans = max(ans, end - cur.second.first);
			end += cur.second.second;
		}

		if(pq.empty() && end < arrive){
			end = fin;
		}
		else{
			pq.push({ch.senior, {ch.arrive, ch.time}});
		} 
	}

	cout << ans;

}
