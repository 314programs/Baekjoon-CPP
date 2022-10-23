#include <bits/stdc++.h>
using namespace std;

//Not very huge data, so I can just use big loops and still get 0ms
int barn1[101] = {0};
int barn2[101] = {0};
//Stores separate data
set<int> s;

void backtrack(int b1, int b2, int day){
    if(day == 5){
        s.insert(b1);
        return;
    }
    if(day%2 == 1){
        for(int i = 0; i <= 100; i++){
            if(barn1[i] > 0){
                barn1[i]--;
                barn2[i]++;
                backtrack(b1-i, b2+i, day+1);
                barn2[i]--;
                barn1[i]++;
            }
        }
    }
    else{
        for(int i = 0; i <= 100; i++){
            if(barn2[i] > 0){
                barn2[i]--;
                barn1[i]++;
                backtrack(b1+i, b2-i, day+1);
                barn1[i]--;
                barn2[i]++;
            }
        }
    }
    return;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    for(int i = 0; i < 10; i++){
        int n;
        cin >> n;
        barn1[n]++;
    }

    for(int i = 0; i < 10; i++){
        int n;
        cin >> n;
        barn2[n]++;
    }

    backtrack(1000, 1000, 1);
    cout << s.size();

}
