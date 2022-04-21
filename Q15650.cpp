#include <bits/stdc++.h>
using namespace std;

int v[9];
int check[9];
int N, M;

void backtrack(int index_){
    if(index_ == M){
        for(int i = 0; i < M; i++){
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 1; i <= N; i++){
        if(check[i] != -1 && (index_ == 0|| v[index_-1] < i)){
            check[i] = -1;
            v[index_] = i;
            backtrack(index_+1);
            v[index_] = 0;
            check[i] = 0;
        }
    }
    
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> N >> M;
    memset(check, 0, 9*4);
    backtrack(0);
    
}
