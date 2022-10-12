#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int n;
    cin >> n;

    long long DP[1000001];
    const long long MOD = 1000000000;

    DP[0] = 0;
    DP[1] = 0;
    DP[2] = 1;
    
    //DP[i-2]*(i-1): Think of this as adding 2 new ppl(I, N) to somewhere < N and end(N) while adding 1 to the remaining group
    //OOO -> IOOON
    //OOO -> OIOON
    //Multiply by (i-1) cause there are N-1 possible positions of I
  
    //DP[i-1]*(i-1): New person N is added, currently there is I and J in the group along with others
    //I gives gift to J while J gives it to others 
    //When N is added I gives gift to N instead, N gives gift to J and J gives it to others
    //Multiply by (i-1) cause there are N-1 possible positions of I
  
    for(int i = 3; i <= n; i++){
        DP[i] = ((DP[i-1]+DP[i-2])*(i-1))%MOD;
    }
    cout << DP[n];

}
