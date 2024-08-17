//Promised myself to do at least gold question, but today's homework + tuition is too much
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int lines;
    cin >> lines;
    cin.ignore();

    while(lines--){
        string s;
        getline(cin, s);
        transform(s.begin(), s.begin()+1, s.begin(), ::toupper);
        cout << s << "\n";
    }

}
