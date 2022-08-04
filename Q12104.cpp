#include <bits/stdc++.h>
using namespace std;

//Kmp
vector<int> pre_processing(string &s){
    int s_len = s.length();
    vector<int> pi(s_len);
    pi[0] = 0;
    int j = 0;

    for(int i = 1; i < s_len; i++){
        while(j > 0 && s[i] != s[j]) j = pi[j-1];
        if(s[i] == s[j]){
            pi[i] = j + 1;
            j++;
        }
        else{
            pi[i] = 0;
        }
    }
    return pi;
}

int match(string & a, string & b){
    vector<int> pi = pre_processing(a);
    int b_len = b.length();
    int a_len = a.length();
    int ans = 0;
    int j = 0;

    for(int i = 0; i < b_len; i++){
        while(j > 0 && b[i] != a[j]) j = pi[j-1];
        if(b[i] == a[j]){
            if(j == a_len-1){
                //Increase count
                ans++;
                j = pi[j];
            }
            else{   
                j++;
            }
        }
    }
    return ans;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
	
    string a, b;
    cin >> a >> b;
    
    //Repeat b to get all shifted lists
    int b_len = b.length();
    for(int i = 0; i < b_len-1; i++){
        b += b[i];
    }

    cout << match(a, b);

}
