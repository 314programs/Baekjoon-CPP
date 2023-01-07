#include <bits/stdc++.h>
using namespace std;

struct person{
    int age;
    string name;
    int idx;
};

bool compare(person u, person v){
    if(u.age == v.age){
        return u.idx < v.idx;
    }
    return u.age < v.age;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    vector<person> num_list(n);
    for(int i = 0; i < n; i++){
        int age;
        string person;
        cin >> age >> person;
        num_list[i] = {age, person, i};
    }

    sort(num_list.begin(), num_list.end(), compare);
    for(auto ch: num_list){
        cout << ch.age << " " << ch.name << "\n";
    }

}
