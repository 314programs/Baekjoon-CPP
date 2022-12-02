//This was... confusing
//Maybe I have to change my mindset 

#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;

    vector<int> diff(n);
    //Difference is the difference between 0 and the current number
    for(int i = 0; i < k; i++){
        int s, e;
        cin >> s >> e;
        s--; e--;
        //Place +1 at start, and -1 at the end+1, as we want the end to have+1 value as well
        diff[s]++;
        diff[e+1]--;
    }

    int val = 0;
    vector<int> final(n);
    //Calculate the value of the final list
    for(int i = 0; i < n; i++){
        val += diff[i];
        final[i] = val;
    }
    
    //Find median
    sort(final.begin(), final.end());
    cout << final[n/2];

}
