#include <bits/stdc++.h>
using namespace std;

int graph[2187][2187];
int count_[3] = {0,0,0};

bool same(int x, int y, int dimension){
    for(int y_ = y; y_ < y + dimension; y_++){
        for(int x_ = x; x_ < x + dimension; x_++){
            if(graph[y_][x_] != graph[y][x]) return false;
        }
    }
    return true;
}

void check(int x, int y, int dimension){
    if(same(x, y, dimension)){
        count_[graph[y][x] + 1] += 1;
        return;
    }

    for(int y_ = y; y_ < dimension + y; y_ += dimension/3){
        for(int x_ = x; x_ < dimension + x; x_ += dimension/3){
            check(x_, y_, dimension/3);
        }
    }

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int dimension;
    cin >> dimension;

    for(int y = 0; y < dimension; y++){
        for(int x = 0; x < dimension; x++){
            cin >> graph[y][x];
        }
    }

    check(0, 0, dimension);
    for(auto ch: count_) cout << ch << "\n";

}
