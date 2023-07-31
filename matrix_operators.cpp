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

matrix power(int n, matrix a){
	if(n == 0){
		return {{1, 0}, {0, 1}};
	}
	else if(n == 1){
		return a;
	}
	else if(n%2 == 0){
		matrix temp = power(n/2, a);
		return temp*temp;
	}
	else{
		return a * power(n-1, a);
	}
}
