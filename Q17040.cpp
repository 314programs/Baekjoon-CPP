#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long


int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    ifstream cin;
    ofstream cout;
    cin.open("revegetate.in");
    cout.open("revegetate.out");

    int n, m;
    cin >> n >> m;
    vector<int> t[n+1];

    string s = "";
    for(int i = 0; i < n; i++){
        s += "0";
    }

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        t[a].push_back(b);
        t[b].push_back(a);
    }
    
    //Thought if previous one is occupied by other grass type, current one has to be greater
    //Just mark the already used grass and it is correct
    for(int i = 1; i <= n; i++){
        bool can[5];
        memset(can, true, sizeof(can));
        for(auto ch: t[i]){
            can[s[ch-1]-'0'] = false;
        }
        for(int j = 1; j <= 4; j++){
            if(can[j]){
                s[i-1] = j+'0';
                break;
            }
        }
    }
    cout << s;

    

}
