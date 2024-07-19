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

	bool graph[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			char a;
			cin >> a;
			if(a == 'X') graph[i][j] = false;
			else graph[i][j] = true;
		}
	}

	string s;
	cin >> s;
	int cnt = 0;

	bool visited[n][n];
	memset(visited, 0, sizeof(visited));
	char ans[n][n];
	memset(ans, '.', sizeof(ans));
	bool can = true;

	for(int m = 0; m < 4; m++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(graph[i][j]){
					ans[i][j] = s[cnt++];
					if(!visited[i][j]){
						visited[i][j] = true;
					}
					else{
						can = false;
					}
				}
			}
		}

		bool temp[n][n];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				temp[i][j] = graph[j][i];
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n/2; j++){
				swap(temp[i][j], temp[i][n-j-1]);
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				graph[i][j] = temp[i][j];
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(!visited[i][j]){
				can = false;
			}
		}
	}
	if(can){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << ans[i][j];
			}
		}
	}
	else{
		cout << "invalid grille";
	}

}
