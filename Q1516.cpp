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
    cin.tie(NULL), cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> time(n+1);

	int indegrees[n+1];
	memset(indegrees, 0, sizeof(indegrees));
	vector<vector<int>> outdegrees(n+1, vector<int>(0));
	vector<vector<int>> need(n+1, vector<int>(0));

	for(int i = 1; i <= n; i++){
		int t;
		cin >> t;
		time[i] = t;

		while(true){
			int num;
			cin >> num;
			if(num == -1) break;

			indegrees[i]++;
			outdegrees[num].push_back(i);
			need[i].push_back(num);
		}
	}

	queue<int> q;
	vector<int> ans(n+1);
	for(int i = 1; i <= n; i++){
		if(indegrees[i] == 0){
			q.push(i);
			ans[i] += time[i];
		}
	}

	//what time each construction finishes
	
	while(!q.empty()){
		int cur = q.front();
		q.pop();

		for(auto ch: outdegrees[cur]){
			indegrees[ch]--;
			ans[ch] = max(ans[cur] + time[ch], ans[ch]);
			if(indegrees[ch] == 0){
				q.push(ch);
			}
		}
	}

	for(int i = 1; i <= n; i++){
		cout << ans[i] << "\n";
	}

}
