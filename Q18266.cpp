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
	int weight, x, direction;
};

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	setIO("");

	int n, l;
	cin >> n >> l;

	vector<cow> a(n);
	int total_weight = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i].weight >> a[i].x >> a[i].direction;
		total_weight += a[i].weight;
	}
	sort(a.begin(), a.end(), [&](cow &u, cow &v){
		return u.x < v.x;
	});

	vector<cow> left;
	vector<cow> right;
	for(auto ch: a){
		if(ch.direction == 1){
			right.push_back(ch);
		}
		else{
			left.push_back(ch);
		}
	}

	vector<pair<int, int>> weight_time;
	for(int i = 0; i < left.size(); i++){
		weight_time.push_back({left[i].x, a[i].weight});
	}
	for(int i = 0; i < right.size(); i++){
		weight_time.push_back({l-right[i].x, a[i+left.size()].weight});
	}
	sort(weight_time.begin(), weight_time.end(), [&](pair<int, int> &u, pair<int, int> &v){
		return u.first < v.first;
	});

	int end_time = -1;
	for(auto &[time, weight]: weight_time){
		total_weight -= weight * 2;
		if(total_weight <= 0){
			end_time = time;
			break;
		}
	}

	int meeting_cnt = 0;
	queue<int> leftside;
	for(int i = 0; i < n; i++){
		if(a[i].direction == 1){
			leftside.push(a[i].x);
		}
		else{
			while(!leftside.empty() && leftside.front() + 2 * end_time < a[i].x){
				leftside.pop();
			}
			meeting_cnt += leftside.size();
		}
	}
	cout << meeting_cnt;

}
