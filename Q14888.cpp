#include <bits/stdc++.h>
using namespace std;

int num_count;
int numbers[11];

int calc(vector<int> & operations){
    long long prev_num = numbers[0];

    for(int i = 1; i < num_count+1; i++){
        int current_operator = operations[i-1];
        if(current_operator == 1) prev_num += numbers[i];
        if(current_operator == 2) prev_num -= numbers[i];
        if(current_operator == 3) prev_num *= numbers[i];
        if(current_operator == 4) prev_num /= numbers[i];
    }

    return prev_num;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> num_count;
    for(int i = 0; i < num_count; i++){
        cin >> numbers[i];
    }

    //1: +; 2: -; 3: *; 4: /
    vector<int> operators;
    for(int i = 1; i <= 4; i++){
        int temp;
        cin >> temp;
        for(int j = 0; j < temp; j++){
            operators.push_back(i);
        }
    }
  
    //No need for sorting for permutations since it will always be in order

    long long minimum = 999999999;
    long long maximum = -999999999;

    do{
        long long temp = calc(operators);
        minimum = min(temp, minimum);
        maximum = max(temp, maximum);
    } while(next_permutation(operators.begin(), operators.end()));

    cout << maximum << "\n" << minimum;
    
}

