#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> store(n);
    //To count how many of integers there are
    int counter[1000001];
    vector<int> answer_(n);
    stack<int> s;
    s.push(0);
    
    //sizeof(int) * size(counter)
    memset(counter, 0, 4000004);

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        answer_[i] = -1;
        counter[num] += 1;
        store[i] = num;
    }
    
    //Same method of comparison as Q17298
    for(int i = 1; i < n; i++){
        while(true){
            if(!s.empty() && counter[store[s.top()]] < counter[store[i]]){
                answer_[s.top()] = store[i];
                s.pop();
            }
            else{
                break;
            }
        }
        s.push(i);
    }
    
    for(int i = 0; i < n; i++){
        cout << answer_[i] << " ";
    }
}
