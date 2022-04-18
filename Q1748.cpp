#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int num;
    long long total_length = 0;
    cin >> num;
  
    //Confusing
    for(int start = 1, len = 1; start <= num; start *= 10, len++){
        int end = (start*10) - 1;
        if(end > num){
            end = num;
        }
        total_length += (long long)(end-start+1)*len;
    }

    cout << total_length;

}
