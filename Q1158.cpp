#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    //Can use queue now instead of making a struct
    queue<int> q;
    int people, skip;

    cin >> people >> skip;

    for(int i = 1; i <= people; i++){
        q.push(i);
    }
    cout << "<";
    while(people-- > 1){
        for(int j = 0; j < skip-1; j++){
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front();
    cout << ">";
    
}
