#include <bits/stdc++.h>
using namespace std;

int dimension;

int column[15];
int diagonal1[31];
int diagonal2[31];
int visited[15][15];

int go(int row){
    int count_ = 0;
    if(row == dimension){
        return 1;
    }

    for(int col = 0; col < dimension; col++){
        if(column[col] == 0 && diagonal1[col + row] == 0 && diagonal2[col - row + dimension] == 0 && visited[row][col] == 0){
            column[col] = 1;
            diagonal1[col + row] = 1;
            diagonal2[col - row + dimension] = 1;
            visited[row][col] = 1;

            count_ += go(row + 1);

            column[col] = 0;
            diagonal1[col + row] = 0;
            diagonal2[col - row + dimension] = 0;
            visited[row][col] = 0;
        }
    }
    return count_;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> dimension;
    cout << go(0);
}


