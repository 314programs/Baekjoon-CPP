#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<vector<long long>> matrix;
const long long mod = 1000000009LL;

int main() {
	string s;
	cin >> s;
	int n = s.length();

	int a = 0, b = 0;
	bool rule = false;
	string winner = "";
	for(int i = 0; i < n; i += 2){
		if(s[i] == 'A'){
			a += s[i+1]-'0';
		}
		else{
			b += s[i+1]-'0';
		}

		if(a == 10 && b == 10) rule = true;

		if(rule){
			if(a - b >= 2){
				winner = "A";
				break;
			}
			if(b - a >= 2){
				winner = "B";
				break;
			}
		}
		else{
			if(a >= 11){
				winner = "A";
				break;
			}
			if(b >= 11){
				winner = "B";
				break;
			}
		}
	}
	cout << winner;

}
