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

int round3(double n){
    return (int)(n*1000.0 + 0.5);
}

bool possible(vector<int> &a, double guess, int n){
    int i, total = 0;
    double best, current;
    for(int i = 0; i < n; i++){
        total += a[i];
    }
    best = current = a[1] - guess;

    for(i = 2; i < n-1; i++){
        if(current < 0) current = 0;
        current += a[i] - guess;
        if(current > best) best = current;
    }
	return (bool)(best >= total - (guess * n));

}
 
int32_t main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);
 
    setIO();

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    double left = 1.0, right = 1e5 * 10000.0;
    while(round3(left) != round3(right)){
        double mid = (left+right)/2;
        if(possible(a, mid, n)){
            right = mid;
        }
        else{
            left = mid;
        }
    }
    cout << fixed << setprecision(3) << left;
 
}
