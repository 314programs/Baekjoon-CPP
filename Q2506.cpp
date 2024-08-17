//Played table tennis with friends today
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    int n;
    cin >> n;

    int score = 0;
    int count = 1;
    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        if(c == 1){
            score += count;
            count++;
        }
        else{
            count = 1;
        }
    }
    cout << score;

}
