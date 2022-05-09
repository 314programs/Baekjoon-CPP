#include <bits/stdc++.h>
using namespace std;

//For storing numeric value of characters using ASCII code
char alpha[256];

int calc(vector<string> &words_, vector<char> &characters_, vector<int> &num_key){
    int sum_ = 0;

    for(int i = 0; i < characters_.size(); i++){
        //Set value to each character
        alpha[characters_[i]] = num_key[i];
    }
    
    //Calculate the sum and return
    for(string ch: words_){
        int now = 0;
        for(char c_: ch){
            now = now*10 + alpha[c_];
        }
        sum_ += now;
    }

    return sum_;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int number_count;
    cin >> number_count;

    vector<string> words(number_count);
    vector<char> characters;
     
    //Input words and store characters
    for(int i = 0; i < number_count; i++){
        cin >> words[i];
        for(char ch: words[i]){
            characters.push_back(ch);
        }
    }
    
    //Sort the characters so that repeating characters can be removed
    sort(characters.begin(), characters.end());
    characters.erase(unique(characters.begin(), characters.end()), characters.end());

    int character_size = characters.size();
    vector<int> number_keys;
  
    //All possible numbers(maximum) is put into vector
    for(int i = 9; i > 9 - character_size; i--){
        number_keys.push_back(i);
    }
    //Sorted for permutations
    sort(number_keys.begin(), number_keys.end());
    
    //Calculate sum for each permutation and output the maximum
    int ans = 0;
    do{
        ans = max(ans, calc(words, characters, number_keys));
    } while(next_permutation(number_keys.begin(), number_keys.end()));

    cout << ans;
    
}

