#include <bits/stdc++.h>
using namespace std;

char convert(char ch){
    if(ch == 'H') return 'T';
    else return 'H';
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int dimension;
    cin >> dimension;

    vector<string> graph(dimension);

    for(int y = 0; y < dimension; y++){
        cin >> graph[y];
    }
    
    int ans = dimension * dimension;
    //Bitmasking used to see which column to flip
    for(int state = 0; state < (1 << dimension); state++){
        int sum_ = 0;
        for(int y = 0; y < dimension; y++){
            int T_count = 0;
            //Flip row depending if it reduces counts of Ts or not
            for(int x = 0; x < dimension; x++){
                char current_ = graph[y][x];
                if(state & (1 << x)){
                    current_ = convert(current_);
                }
                if(current_ == 'T'){
                    T_count += 1;
                }
            }
            sum_ += min(T_count, dimension - T_count);
        }
        //Answer is minimum
        ans = min(sum_, ans);
    }
    cout << ans;

}
