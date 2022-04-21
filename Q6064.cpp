#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int testcase;
    cin >> testcase;

    while(testcase--){
        int M,N,x,y;
        cin >> M >> N >> x >> y;
        //To make conversion easier
        x -= 1;
        y -= 1;
        
        bool found = false;
        for(int i = x; i < M*N; i+=M){
            if(i%N == y){
                found = true;
                //To make up for subtraction done
                cout << i+1 << "\n";
                break;
            }
        }

        if(!found){
            cout << -1 << "\n";
        }

    }
}
