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

bool visited[1005];

int32_t main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;

		memset(visited, 0, sizeof(visited));
		vector<int> connection(n+1);
		for(int i = 1; i <= n; i++){
			cin >> connection[i];
		}

		int cycles = 0;
		for(int i = 1; i <= n; i++){
			if(!visited[i]){
				cycles++;
				visited[i] = true;
				queue<int> q;
				q.push(i);

				while(!q.empty()){
					int cur = q.front();
					q.pop();

					int next = connection[cur];
					if(!visited[next]){
						visited[next] = true;
						q.push(next);
					}
				}
			}
		}
		cout << cycles << "\n";
	}

}
