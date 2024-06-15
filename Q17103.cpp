#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int testcase;
    cin >> testcase;
    
    //Make primes
    int primecheck[1000001];
    int primes[100000];
    int index_ = 0;

    memset(primecheck, 0, 1000001*4);
    primecheck[0] = 1;
    primecheck[1] = 1;

    for(int i = 2; i < 1000001; i++){
        if(primecheck[i] == 0){
            primes[index_++] = i;
            for(int j = i*2; j < 1000001; j+=i){
                primecheck[j] = 1;
            }
        }
    }

    while(testcase--){
        int num;
        int idx = 0;
        int possibility = 0;
        cin >> num;
        
        //Divide by half to avoid combinations
        while(primes[idx] < (num/2) + 1){
            if(primecheck[num - primes[idx]] == 0){
                possibility += 1;
            }
            idx++;
        }

        cout << possibility << "\n";
    }


}
