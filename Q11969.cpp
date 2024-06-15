//Did this quickly during chinese lesson
//Must study maths at home...

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

struct cow{
    int hol, gur, jer;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<cow> a(n+1);
    a[0].hol = 0;
    a[0].gur = 0;
    a[0].jer = 0;

    for(int i = 1; i <= n; i++){
        int t;
        cin >> t;
        a[i] = a[i-1];

        if(t == 1) a[i].hol++;
        else if(t == 2) a[i].gur++;
        else a[i].jer++;
    }

    for(int i = 0; i < m; i++){
        int s, e;
        cin >> s >> e;
        cout << a[e].hol - a[s-1].hol << " " << a[e].gur - a[s-1].gur << " " << a[e].jer - a[s-1].jer << "\n";
    }
    

}
