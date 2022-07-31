vector<int> pre_process(string s){
    int s_len = s.size();
    vector<int> pi(s_len);
    pi[0] = 0;
    int j = 0;

    for(int i = 1; i < s_len; i++){
        while(j > 0 && s[i] != s[j]) j = pi[j-1];
        if(s[i] == s[j]){
            pi[i] = j+1;
            j++;
        }  
        else{
            pi[i] = 0;
        }
    }
    return pi;
}

vector<int> match(string s, string p){
    auto pi = pre_process(p);
    //Stores index of when p starts inside s
    vector<int> ans;
    int s_len = s.size(), p_len = p.size();
    int j = 0;

    for(int i = 0; i < s_len; i++){
        while(j > 0 && s[i] != p[j]) j = pi[j-1];
        if(s[i] == p[j]){
            if(j == p_len - 1){
                ans.push_back(i-p_len+1);
                j = pi[j];
            }
            else{
                j++;
            }
        }
    }
    return ans;
}
