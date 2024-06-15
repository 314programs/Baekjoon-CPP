#include <bits/stdc++.h>
using namespace std;

struct person{
    string name;
    int korean;
    int english;
    int math;
};

bool compare(person u, person v){
    if(u.korean == v.korean && u.english == v.english && u.math == v.math){
        return u.name < v.name;
    }
    else if(u.korean == v.korean && u.english == v.english){
        return u.math > v.math;
    }
    else if(u.korean == v.korean){
        return u.english < v.english;
    }
    return u.korean > v.korean;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    vector<person> num_list(n);
    for(int i = 0; i < n; i++){
        string name_;
        int k, e, m;
        cin >> name_ >> k >> e >> m;
        num_list[i] = {name_, k, e, m};
    }

    sort(num_list.begin(), num_list.end(), compare);
    for(auto ch: num_list){
        cout << ch.name << "\n";
    }

}
