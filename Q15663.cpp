#include <bits/stdc++.h>
using namespace std;

int a[10];
int num[10];
int cnt[10];
int N, M;

void backtrack(int index_){
    if(index_ == M){
        for(int i = 0; i < M; i++){
            cout << num[a[i]] << " ";
        }
        cout << "\n";
    }

    for(int i=0; i < N; i++){
        if(cnt[i] > 0){
            cnt[i] -= 1;
            a[index_] = i;
            backtrack(index_ + 1);
            cnt[i] += 1;
        }
    }
    
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;
    int temp[10];

    for(int i = 0; i < N; i++){
        cin >> temp[i];
    }
    sort(temp, temp+N);

    int k = 0;
    int x = temp[0];
    int c = 1;

    for(int i = 1; i < N; i++){
        if(x == temp[i]){
            c += 1;
        }
        else{
            num[k] = x;
            cnt[k] = c;
            k += 1;
            x = temp[i];
            c = 1;
        }
    }

    num[k] = x;
    cnt[k] = c;
    N = k + 1;
    backtrack(0);
    
}
