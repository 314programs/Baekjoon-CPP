//Simple queue question...

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    queue<int> q;
    int s = 0;
    cin >> s;

    while(true){
        int n;
        cin >> n;

        if(n == -1) break;

        if(n == 0) q.pop();
        else if(q.size() < s) q.push(n);

    }

    if(q.empty()) cout << "empty";
    else{
        while(!q.empty()){
            cout << q.front() << " ";
            q.pop();
        }
    }

}
