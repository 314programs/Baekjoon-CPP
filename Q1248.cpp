//May try redoing this again in the future
//Took me a while to understand the problem

#include <bits/stdc++.h>
using namespace std;

int dimension;
int matrix[10][10];
int nums[10];

//Checking vertically using the matrix values
bool check_matrix(int index_){
    int sum_ = 0;
    for(int i = index_; i >= 0; i--){
        sum_ += nums[i];
        if(matrix[i][index_] == 0){
            if(sum_ != 0) return false;
        }
        else if(matrix[i][index_] == -1){
            if(sum_ >= 0) return false;
        }
        else if(matrix[i][index_] == 1){
            if(sum_ <= 0) return false;
        }
    }
    //Only return true after all criteria has been matched
    return true;
}

bool backtrack(int index_){
    if(index_ == dimension){
        return true;
    }

    if(matrix[index_][index_] == 0){
        //Don't need to do if(...) because there is only 1 option, no need to loop
        return check_matrix(index_)&&backtrack(index_+1);
    }
    for(int i = 0; i <= 10; i++){
        nums[index_] = i * matrix[index_][index_];
        //If both of them is true, return true
        //Else repeat the loop until it ends
        if(check_matrix(index_)&&backtrack(index_+1)) return true;
    }

    return false;

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> dimension;
    string signs;
    cin >> signs;

    memset(matrix, '0', sizeof(matrix));
  
    //Input values into matrix
    int idx_ = 0;
    for(int i = 0; i < dimension; i++){
        for(int j = i; j < dimension; j++){
            if(signs[idx_] == '0'){
                matrix[i][j] = 0;
            }
            else if(signs[idx_] == '+'){
                matrix[i][j] = 1;
            }
            else if(signs[idx_] == '-'){
                matrix[i][j] = -1;
            }
            idx_ += 1;
        }
    }

    backtrack(0);
    
    //Print
    for(int i = 0; i < dimension; i++){
        cout << nums[i] << " ";
    }

    
}

