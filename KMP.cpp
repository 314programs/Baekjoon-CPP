vector<int> pre_processing(string p){
    //Vector pi, is for measuring fail element
    //The vector pi records when prefix = suffix, and the number is the length of each
    //Here is a fail vector of AABABAAB
    //0 1 0 1 0 1 2 3
    //First index A is repeated, then at the 3rd index prefix = suffix for 1 length
    //At the end, AAB(prefix) == AAB(suffix) with length of 3.
    
    int m = p.size();
    vector<int> pi(m);
    pi[0] = 0;
    int j = 0;
    
    for(int i = 1; i < m; i++){
        //j is the longest length of prefix
        //Keep descreasing j until p[i] == p[j] or it cannot be decreased anymore
        while(j > 0 && p[i] != p[j]) j = pi[j-1];

        //If p[i] and p[j] are equal, increase length of j and record
        if(p[i] == p[j]){
            pi[i] = j+1;
            j += 1;
        }
        //Reset to 0 when it doesn't match
        else{
            pi[i] = 0;
        }
    }
    return pi;
}

vector<int> kmp(string s, string p){
    //Similar to pre_processing but uses the fail vector
    auto pi = pre_processing(p);
    vector<int> ans;
    int n = s.size(), m = p.size(), i = 0, j = 0;

    for(int i = 0; i < n; i++){
        //Same reason as previous
        while(j > 0 && s[i] != p[j]) j = pi[j-1];

        if(s[i] == p[j]){
            //Means current character is end of string p, meaning that the ending index of p has been found
            //However to make the algorithm output the starting index, length of p has to be subtracted
            if(j == m-1){
                ans.push_back(i-m+1);
                //Change the starting point of comparison
                j = pi[j];
            }
            else{
                j += 1;
            }
        }
    }
    return ans;
}
