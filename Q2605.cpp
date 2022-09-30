#include <bits/stdc++.h>
using namespace std;

//Insert function...
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        a.insert(a.begin() + a.size()-num, i+1);
    }
    
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    
}
