#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    //Right is min_heap
    priority_queue<int, vector<int>, greater<int>> right;
    //Left is max_heap
    priority_queue<int> left;

    int num_count;
    cin >> num_count;
    
    //Smallest element in right must be bigger then biggest element on left
    while(num_count--){
        int num;
        cin >> num;

        if(left.size() == right.size()){
            left.push(num);
        }
        else if(right.size() < left.size()){
            right.push(num);
        }
        
        //If smallest element in right is smaller then biggest element on left swap them
        while(!left.empty() && !right.empty() && left.top() > right.top()){
            int l = left.top();
            int r = right.top();
            left.pop(); right.pop();
            left.push(r); right.push(l);
        }

        cout << left.top() << "\n";

    }

}
