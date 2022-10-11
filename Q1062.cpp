#include <bits/stdc++.h>
using namespace std;

int count_(vector<int> & words, int learned){
    int count_ = 0;
    for(auto ch: words){
        //Check if all alphabet in word has been learned
        //(1 << 26)-1 is bitset of length 25 filled with 1s
        //-learned converts learned alphanet from 1s into 0s
        //If all alphabet has been learned, operation should equal to 0, as there will be no overlapping 1s.
        if((ch & (1 << 26)-1-learned) == 0){
            count_ += 1;
        }
    }
    return count_;
}

int calc(vector<int> & words, int index_, int can_learn, int learned){
    if(can_learn < 0) return 0;
    //Return possible words to learn
    if(index_ == 26) return count_(words, learned);
    
    int ans = 0;
    if(can_learn > 0 && index_ != 0 && index_ != 2 && index_ != 8 && index_ != 13 && index_ != 19){
        //Learn new alphabet if possible
        ans = max(ans, calc(words, index_ + 1, can_learn-1, learned | (1 << index_))); 
    }
    //Just continue on
    ans = max(ans, calc(words, index_ + 1, can_learn, learned));
    return ans;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int word_count, teach_count;
    cin >> word_count >> teach_count;

    vector<int> words(word_count);
    for(int i = 0; i < word_count; i++){
        string temp;
        cin >> temp;
        
        //Cutting out the edge to make it go quicker
        for(int j = 4; j < temp.length()-4; j++){
            words[i] |= (1 << (temp[j] - 'a'));
        }
    }
    
    //Assume that the alphabets in antatica is learned since it will always appear
    //If number of alphabets that can be teached is smaller then 5, if(can_learn < 0) return 0; in calc can take care of it.
    teach_count -= 5;
    int mask = 0;
    mask |= 1 << 0;
    mask |= 1 << 2;
    mask |= 1 << 8;
    mask |= 1 << 13;
    mask |= 1 << 19;

    cout << calc(words, 0, teach_count, mask);

}


 
