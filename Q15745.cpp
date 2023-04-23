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

struct boot{
	int max_depth, max_step, index;
};

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	setIO("snowboots");

	int n, m;
	cin >> n >> m;

	vector<int> tiles(n);
	for(int i = 0; i < n; i++){
		cin >> tiles[i];
	}

	vector<boot> boots(m);
	for(int i = 0; i < m; i++){
		cin >> boots[i].max_depth >> boots[i].max_step;
		boots[i].index = i;
	}
	sort(boots.begin(), boots.end(), [&](boot &u, boot &v){
		return u.max_depth > v.max_depth;
	});

	vector<int> tile_depth;
	for(int i = 1; i < n-1; i++){
		tile_depth.push_back(i);
	}
	sort(tile_depth.begin(), tile_depth.end(), [&](int u, int v){
		return tiles[u] > tiles[v];
	});

	set<int> valid_tiles;
	for(int i = 0; i < n; i++){
		valid_tiles.insert(i);
	}

	int tile_at = 0;
	int needed_step = 1;
	vector<bool> can_reach(m);
	for(boot &b: boots){
		while(tile_at < tile_depth.size() && tiles[tile_depth[tile_at]] > b.max_depth){
			auto removed = valid_tiles.find(tile_depth[tile_at]);
			needed_step = max(needed_step, *next(removed) - *prev(removed));
			valid_tiles.erase(removed);
			tile_at++;
		}
		can_reach[b.index] = (b.max_step >= needed_step);
	}

	for(auto ch: can_reach){
		cout << ch << "\n";
	}


}
