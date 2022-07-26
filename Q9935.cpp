#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    string s;
    getline(cin, s);
    int s_len = s.length();

    string explode;
    getline(cin, explode);
    int explode_len = explode.length();

    stack<char> st;
    for(int j = 0; j < s_len; j++){
        char ch = s[j];
        st.push(ch);
        
        //If last char of explode and stack is equal && stack is bigger then the size of exploding string
        if(st.top() == explode.back() && st.size() >= explode_len){
            string temp = "";
            for(int i = 0; i < explode_len; i++){
                temp += st.top();
                st.pop();
            }
            reverse(temp.begin(), temp.end());
            //If temp is not the exploding string, put the characters back into the stack
            if(temp != explode){
                for(auto ch: temp){
                    st.push(ch);
                }
            }
        }
    }

    string ans = "";
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    if(ans != "") cout << ans;
    else cout << "FRULA";

}
