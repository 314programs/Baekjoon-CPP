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
 
int32_t main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);
 
    setIO();

    int n;
	cin >> n;

	vector<pair<pair<int, int>, int>> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i].first.first >> a[i].first.second;
		a[i].second = i;
	}
	sort(a.begin(), a.end());

	int last_room = 0;
	priority_queue<pair<int, int>> pq;
	for(int i = 0; i < n; i++){
		int room_used;
		if(pq.empty()){
			last_room++;
			room_used = last_room;
		}
		else{
			pair<int, int> minimum = pq.top();
			if(-minimum.first <= a[i].first.first){
				pq.pop();
				room_used = minimum.second;
			}
			else{
				last_room++;
				room_used = last_room;
			}
		}
		pq.push({-a[i].first.second, room_used});
	}
	cout << last_room;

}
