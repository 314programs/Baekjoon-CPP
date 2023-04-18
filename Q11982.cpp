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

pair<int, int> calc(vector<int> &a, int r, int &pos, int &n){
	int idx = lower_bound(a.begin(), a.end(), pos) - a.begin();
	if(idx == n) idx--;

	int cur_l = pos, cur_r = pos;
	int idx_l = idx, idx_r = idx;
 
	while(true){
		bool can_l = false, can_r = false;
		while(idx_l > 0 && cur_l - r <= a[idx_l]){
			idx_l--;
			can_l = true;
		}
		while(idx_r < n-1 && cur_r + r >= a[idx_r]){
			idx_r++;
			can_r = true;
		}
		cur_l = a[idx_l];
		cur_r = a[idx_r];
		r--;


		if(!(can_l && can_r)) break;
	}
	return make_pair(idx-idx_l, idx_r-idx);
}

bool possible_pos(vector<int> &a, int &r, int &n){
	int left = 0, right = a.back();
	while(left <= right){
		int mid = (left+right)/2;
		cout << mid << "\n";
		pair<int, int> dist = calc(a, r, mid, n);

		//First = left, Second = right
		if(dist.first + dist.second >= n){
			return true;
		}

		if(dist.first < dist.second){
			left = mid+1;
		}
		else{
			right = mid-1;
		}
	}
	return false;
}

int32_t main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);
 
    setIO("");

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
		a[i] *= 2;
    }
	sort(a.begin(), a.end());

	int left = 0, right = 2e9;
	while(left <= right){
		int mid = (left+right)/2;
		if(possible_pos(a, mid, n)){
			right = mid-1;
		}
		else{
			left = mid+1;
		}
	}

	cout << fixed << setprecision(1) << (double)(right+1)/2;
 
}
