#include <bits/stdc++.h>
using namespace std;

int v[8];
int num_list[8];
int check[8];
int N, M;

void backtrack(int index_){
    if(index_ == M){
        for(int i = 0; i < M; i++){
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 0; i < N; i++){
        if(check[i] != -1 && (index_ == 0 || v[index_-1] < num_list[i])){
            check[i] = -1;
            v[index_] = num_list[i];
            backtrack(index_+1);
            v[index_] = 0;
            check[i] = 0;
        }
    }
    
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    memset(check, 0, 8*4);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> num_list[i];
    }
    sort(num_list, num_list+N);

    backtrack(0);
    
}
