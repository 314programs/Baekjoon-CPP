int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> ans(m, vector<int>(m));
	vector<vector<int>> even(m, vector<int>(m));
	vector<vector<int>> odd(m, vector<int>(m));
	vector<vector<int>> a(m, vector<int>(m));

	for(int i = 0; i < m; i++){
		ans[i][i] = 1;
		odd[i][i] = 1;
		if(i-1 >= 0){
			odd[i][i-1] = 1;
			even[i][i-1] = 1;
		}
		if(i+1 < m){
			odd[i][i+1] = 1;
			even[i][i+1] = 1;
		}
	}
	n--;
	a = even * odd;

	int p = n/2;
	while(p > 0){
		if(p%2 == 1){
			ans = ans * a;
		}
		a = a*a;
		p /= 2;
	}

	if(n%2 == 1){
		ans = ans * even;
	}

	int total = 0;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			total += ans[i][j];
			total %= mod;
		}
	}
	cout << total;

}
