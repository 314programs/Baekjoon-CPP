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

int vec[21253];

void mark(int num, int change){
	int cur = num;
	vec[cur]++;
	while(cur > 0){
		cur -= change;
		if(cur <= 0) break;
		vec[cur]++;
	}

	cur = num;
	while(true){
		cur += change;
		if(cur > 21252) break;
		vec[cur]++;
	}
	return;
}

int32_t main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int cnt = 1;
	while(true){
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		if(a == -1){
			break;
		}
		for(int i = 0; i < 21253; i++){
			vec[i] = 0;
		}

		cout << "Case " << cnt << ": the next triple peak occurs in ";
		int cur_day = d;

		mark(a, 23);
		mark(b, 28);
		mark(c, 33);
		cnt++;

		for(int i = d+1; i < 21253; i++){
			if(vec[i] == 3){
				cur_day = i;
				break;
			}
		}

		cout << cur_day - d << " days.\n";
		
	}

} 
