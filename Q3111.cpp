#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    string remove;
    cin >> remove;
    int remove_len = remove.length();

    string s;
    cin >> s;
    
    stack<char> r;
    stack<char> l;
    int left = 0, right = s.length()-1;
    
    //Until they meet
    while(left != right+1){
        //BACK
        while(left <= right){
            l.push(s[left++]);
            if(l.top() == remove.back() && l.size() >= remove_len){
                string temp = "";
                for(int i = 0; i < remove_len; i++){
                    temp += l.top();
                    l.pop();
                }
                reverse(temp.begin(), temp.end());
                if(temp != remove){
                    for(int i = 0; i < remove_len; i++){
                        l.push(temp[i]);
                    }
                }
                else{
                    break;
                }
            }
        }
        
        //FRONT
        while(left <= right){
            r.push(s[right--]);
            if(r.top() == remove.front() && r.size() >= remove_len){
                string temp = "";
                for(int i = 0; i < remove_len; i++){
                    temp += r.top();
                    r.pop();
                }
                if(temp != remove){
                    for(int i = remove_len-1; i >= 0; i--){
                        r.push(temp[i]);
                    }
                }
                else{
                    break;
                }
            }
        }
    }

    string ans = "";
    //Move all elements of left to right side, keep removing words from there too

    while(!l.empty()){
        r.push(l.top());
        l.pop();
        if(r.top() == remove.front() && r.size() >= remove_len){
            string temp = "";
            for(int i = 0; i < remove_len; i++){
                temp += r.top();
                r.pop();
            }
            if(temp != remove){
                for(int i = remove_len-1; i >= 0; i--){
                    r.push(temp[i]);
                }
            }
        }
    }
    
    //Print
    while(!r.empty()){
        ans += r.top();
        r.pop();
    }
    cout << ans;


}
