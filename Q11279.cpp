#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int num_cnt;
    cin >> num_cnt;
    priority_queue<int> pq;

    while(num_cnt--){
        int num;
        cin >> num;
        if(num == 0){
            if(pq.empty()) cout << "0\n";
            else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else{
            pq.push(num);
        }
    }

}
