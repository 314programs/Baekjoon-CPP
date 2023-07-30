typedef vector<vector<int>> matrix;
const int MOD = 1000000007;

matrix operator * (const matrix &a, const matrix &b){
	int n =  a.size();
	matrix c (n, vector<int> (n));

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				c[i][j] += a[i][k] * b[k][j];
			}
			c[i][j] %= MOD;
		}
	}
	return c;
}
