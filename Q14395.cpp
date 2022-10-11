#include <bits/stdc++.h>
using namespace std;

struct datas{
    long long num;
    string method;
};


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    long long start, end;
    long long limit = 1000000000;
    cin >> start >> end;

    set<long long> check;
    queue<datas> q_;
    q_.push({start, ""});
    check.insert(start);

    while(!q_.empty()){
        datas temp = q_.front();
        q_.pop();

        if(temp.num == end){
            if(temp.method == ""){
                cout << 0;
                return 0;
            }
            cout << temp.method;
            return 0;
        }
        
        //IN ASCII order
        if(0 <= temp.num * temp.num && check.count(temp.num*temp.num) == 0 && temp.num*temp.num <= limit){
            q_.push({temp.num * temp.num, temp.method + "*"});
            check.insert(temp.num*temp.num);
        }
        if(0 <= temp.num + temp.num && check.count(temp.num+temp.num) == 0 && temp.num+temp.num <= limit){
            q_.push({temp.num + temp.num, temp.method + "+"});
            check.insert(temp.num+temp.num);
        }
        if(0 <= temp.num - temp.num && check.count(temp.num-temp.num) == 0 && temp.num-temp.num <= limit){
            q_.push({temp.num - temp.num, temp.method + "-"});
            check.insert(temp.num-temp.num);
        }
        if(temp.num != 0 && 0 <= temp.num / temp.num && check.count(temp.num/temp.num) == 0 && temp.num/temp.num <= limit){
            q_.push({temp.num / temp.num, temp.method + "/"});
            check.insert(temp.num/temp.num);
        }
    }
    cout << -1;
}
