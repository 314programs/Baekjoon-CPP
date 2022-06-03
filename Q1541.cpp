#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string equation;
    getline(cin, equation);

    vector<int> symbols;
    vector<int> numbers;

    symbols.push_back(1);
    string current;

    for(char ch: equation){
        if(ch == '+'){
            numbers.push_back(stoi(current));
            current = "";
            symbols.push_back(1);
        }
        else if(ch == '-'){
            numbers.push_back(stoi(current));
            current = "";
            symbols.push_back(-1);
        }
        else{
            current += ch;
        }
    }
    numbers.push_back(stoi(current));

    bool minus = false;
    int ans = 0;

    for(int i = 0; i < size(numbers); i++){
        if(symbols[i] == -1) minus = true;

        if(minus != true) ans += numbers[i];
        else ans -= numbers[i];
    }
    cout << ans;
}
