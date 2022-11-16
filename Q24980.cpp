//This could have been done by just counting how many a[i] is different from s[i]...
//THIS TOOK 3 HOURS CAUSE OF THE REPEATED LENGTHS
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

struct besides{
    int left, right;
};

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    //ifstream cin("outofplace.in");
    //ofstream cout("outofplace.out");

    int n;
    cin >> n;

    vector<int> a(n);
    vector<besides> b(n);
    vector<int> s(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        s[i] = a[i];
    }

    sort(s.begin(), s.end());
    map<int, besides> m;
    for(int i = 1; i < n-1; i++){
        if(m.count(s[i]) != 0){
            m[s[i]] = {min(s[i-1], m[s[i]].left), max(s[i+1], m[s[i]].right)};
        }
        else{
            m[s[i]] = {s[i-1], s[i+1]};
        }
    }


    //881697

    int bessie = 0;
    int a_idx = 0;
    if(a[0] != s[0]){
        bessie = a[0];
    }
    else if(a[n-1] != s[n-1]){
        bessie = a[n-1];
        a_idx = n-1;
    }
    else{
        for(int i = 1; i < n; i++){
            int cur = a[i];
            if(cur != s[i] && a[i+1] != m[cur].right && a[i+1] != a[i] && a[i-1] != m[cur].left && a[i-1] != a[i]){
                bessie = a[i];
                a_idx = i;
            }
        }
    }


    int b_idx = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == bessie){
            b_idx = i;
        }
    }


    set<int> ans;
    for(int i = min(a_idx, b_idx); i <= max(a_idx, b_idx); i++){
        ans.insert(a[i]);
    }
    cout << ans.size()-1;

}
