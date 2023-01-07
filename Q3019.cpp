#include <bits/stdc++.h>
using namespace std;

//Not hard, just tedious
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int columns, block_num;
    cin >> columns >> block_num;

    vector<int> height(columns);
    for(int i = 0; i < columns; i++){
        cin >> height[i];
    }

    int ans = 0;
    if(block_num == 1){
        ans += columns;
        for(int i = 0; i < columns - 3; i++){
            if(height[i] == height[i+1] && height[i] == height[i+2] && height[i] == height[i+3]){
                ans += 1;
            }
        }
    }
    if(block_num == 2){
        for(int i = 0; i < columns - 1; i++){
            if(height[i] == height[i+1]){
                ans += 1;
            }
        }
    }
    if(block_num == 3){
        for(int i = 0; i < columns - 2; i++){
            if(height[i] == height[i+1] && height[i] + 1 == height[i+2]){
                ans += 1;
            }
        }
        for(int i = 0; i < columns - 1; i++){
            if(height[i] == height[i+1] + 1){
                ans += 1;
            }
        }
    }
    if(block_num == 4){
        for(int i = 0; i < columns - 2; i++){
            if(height[i+2] == height[i+1] && height[i] - 1 == height[i+2]){
                ans += 1;
            }
        }
        for(int i = 0; i < columns - 1; i++){
            if(height[i] == height[i+1] - 1){
                ans += 1;
            }
        }
    }
    if(block_num == 5){
        for(int i = 0; i < columns - 2; i++){
            if(height[i] == height[i+2] && height[i] - 1 == height[i+1]){
                ans += 1;
            }
            if(height[i] == height[i+1] && height[i] == height[i+2]){
                ans += 1;
            }
        }
        for(int i = 0; i < columns - 1; i++){
            if(height[i] == height[i+1] - 1 || height[i] == height[i+1] + 1){
                ans += 1;
            }
        }
    }
    if(block_num == 6){
        for(int i = 0; i < columns - 2; i++){
            if(height[i] == height[i+1] && height[i] == height[i+2]){
                ans += 1;
            }
            if(height[i] + 1 == height[i+1] && height[i] + 1 == height[i+2]){
                ans += 1;
            }
        }
        for(int i = 0; i < columns - 1; i++){
            if(height[i] == height[i+1]){
                ans += 1;
            }
            if(height[i]-2 == height[i+1]){
                ans += 1;
            }
        }
    }
    if(block_num == 7){
        for(int i = 0; i < columns - 2; i++){
            if(height[i] == height[i+1] && height[i] == height[i+2]){
                ans += 1;
            }
            if(height[i] == height[i+1] && height[i]-1 == height[i+2]){
                ans += 1;
            }
        }
        for(int i = 0; i < columns - 1; i++){
            if(height[i] == height[i+1]){
                ans += 1;
            }
            if(height[i]+2 == height[i+1]){
                ans += 1;
            }
        }
    }
    cout << ans;

}
