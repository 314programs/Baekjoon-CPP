#include <bits/stdc++.h>
using namespace std;

int gdc(int a, int b){
    if(b == 0){
        return a;
    }
    else{
        return gdc(b, a%b);
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int testcase;
    int nums[101];
    cin >> testcase;
    cin.ignore();

    while(testcase--){
        int num_count;
        //Total can go over integer limit
        long total = 0;
        cin >> num_count;
        //Input
        for(int i = 0; i < num_count; i++){
            int temp_num;
            cin >> temp_num;
            nums[i] = temp_num;
        }
        
        //Combination of values, then adding them together
        for(int i = 0; i < num_count; i++){
            for(int j = i+1; j < num_count; j++){
                total += gdc(nums[i], nums[j]);
            }
        }
        cout << total << "\n";
    }
    
}
