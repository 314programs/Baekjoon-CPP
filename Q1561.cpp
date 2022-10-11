#include <bits/stdc++.h>
using namespace std;

//Calculates how many kids have finished riding
long long calc(long long minutes, vector<long long> & play){
    long long kid_count = play.size();
    for(auto ch: play){
        kid_count += minutes/ch;
    }
    return kid_count;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    long long kid_num, play_num;
    cin >> kid_num >> play_num;

    vector<long long> play(play_num);
    for(int i = 0; i < play_num; i++){
        cin >> play[i];
    }

    if(kid_num <= play_num){
        cout << kid_num;
        return 0;
    }
    
    //Binary search = minute passed since 0
    //To find the highest number of kids that is below kid_num
    long long left = 0, right = (2000000000LL*10000LL*30LL)+1;
    long long ans = 0;
    while(left <= right){
        long long mid = (left+right)/2;
        if(calc(mid, play) >= kid_num){
            right = mid - 1;
            
        }
        else{
            ans = mid;
            left = mid + 1;
        }
    }

    long long count = kid_num - calc(ans, play);
    ans += 1;
    
    //Calculate the next ride number
    for(int i = 0; i < play_num; i++){
        if(ans%play[i] == 0){
            count--;
            if(count == 0){
                cout << i+1;
                return 0;
            }
        }
    }
    

}
