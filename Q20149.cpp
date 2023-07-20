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

int CCW(int x1, int y1, int x2, int y2, int x3, int y3){
    int ans = x1*y2 + x2*y3 + x3*y1;
    ans -= y1*x2 + y2*x3 + y3*x1;
    if(ans == 0) return 0;
    else if(ans > 0) return 1;
    else return -1;
}

void coords(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4){
	cout << fixed << setprecision(11);
	double px = (x1*y2 - y1*x2) * (x3 - x4) - (x1 - x2) * (x3*y4 - y3*x4);
	double py = (x1*y2 - y1*x2) * (y3 - y4) - (y1 - y2) * (x3*y4 - y3*x4);
	double p = (y4-y3)*(x2-x1) - (y2-y1)*(x4-x3);

	if(p == 0){
		pair<double, double> A = {x1, y1}, B = {x2, y2}, C = {x3, y3}, D = {x4, y4};
		if(A > B) swap(A, B);
		if(C > D) swap(C, D);

		if(B == C && A <= C) cout << B.first << " " << B.second;
		else if(A == D && C <= A) cout << A.first << " " << A.second;
	}
	else{
		cout << px/p << " " << py/p;
	}
}


int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), std::cout.tie(NULL);
	
	double x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	double x3, y3, x4, y4;
	cin >> x3 >> y3 >> x4 >> y4;

	int temp1 = CCW(x1, y1, x2, y2, x3, y3) * CCW(x1, y1, x2, y2, x4, y4);
    int temp2 = CCW(x3, y3, x4, y4, x1, y1) * CCW(x3, y3, x4, y4, x2, y2);

    if(temp1 == 0 && temp2 == 0){
        pair<int, int> line1_min = min(make_pair(x1, y1), make_pair(x2, y2));
        pair<int, int> line1_max = max(make_pair(x1, y1), make_pair(x2, y2));
        pair<int, int> line2_min = min(make_pair(x3, y3), make_pair(x4, y4));
        pair<int, int> line2_max = max(make_pair(x3, y3), make_pair(x4, y4));

		//Forming 1 line
        if(line2_min <= line1_max && line1_min <= line2_max){
            cout << 1 << "\n";
			coords(x1, y1, x2, y2, x3, y3, x4, y4);
        }
        else{
            cout << 0 << "\n";
        }
    }
    else if(temp1 <= 0 && temp2 <= 0){
        cout << 1 << "\n";
		coords(x1, y1, x2, y2, x3, y3, x4, y4);
    }
    else{
        cout << 0 << "\n";
    }

}
