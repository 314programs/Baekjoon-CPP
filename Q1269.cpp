//Fast enough...

#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    set<int> s;
    set<int> repeat;
    for(int i = 0; i < n+m; i++){
        int num;
        cin >> num;
        if(s.count(num) == 0){
            s.insert(num);
        }
        else{
            repeat.insert(num);
        }
        
    }
    cout << s.size() - repeat.size();

}
