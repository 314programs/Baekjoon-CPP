#include <bits/stdc++.h>
using namespace std;

string check_and_return(string num, int index, int change){
    if(index == 0 && change == 0) return "-1";
    if(num[index] == change + '0') return "-1";
    num[index] = change + '0';
    return num;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int primes[10000];
    memset(primes, 0, sizeof(primes));

    for(int i = 2; i * i < 10000; i++){
        if(primes[i] == 0){
            for(int j = i + i; j < 10000; j += i){
                primes[j] = -1;
            }
        }
    }
    
    int testcase;
    cin >> testcase;

    while(testcase--){
        string start, end;
        cin >> start >> end;

        int visited[10000];
        memset(visited, -1, sizeof(visited));
        visited[stoi(start)] = 0;

        queue<string> q_;
        q_.push(start);

        while(!q_.empty()){
            string temp = q_.front();
            q_.pop();

            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 10; j++){
                    string value = check_and_return(temp, i, j);
                    if(value == "-1" || primes[stoi(value)] != 0 || visited[stoi(value)] != -1) continue;
                    
                    visited[stoi(value)] = visited[stoi(temp)] + 1;
                    if(value == end) break;
                    q_.push(value);
                }
            }
        }

        cout << visited[stoi(end)] << "\n";

    }

}
