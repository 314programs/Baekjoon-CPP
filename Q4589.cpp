#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int num;
    cin >> num;

    vector<int> gnome_unordered(3);
    vector<int> gnome_ordered_asc(3);
    vector<int> gnome_ordered_dsc(3);
    cout << "Gnomes:\n";
    for(int i = 0; i < num; i++){
        for(int j = 0; j < 3; j++){
            cin >> gnome_unordered[j];
            gnome_ordered_asc[j] = gnome_unordered[j];
            gnome_ordered_dsc[j] = gnome_unordered[j];
        }
        sort(gnome_ordered_asc.begin(), gnome_ordered_asc.end());
        sort(gnome_ordered_dsc.begin(), gnome_ordered_dsc.end(), greater<int>());

        if(gnome_ordered_asc == gnome_unordered || gnome_ordered_dsc == gnome_unordered) cout << "Ordered\n";
        else cout << "Unordered\n";
    }
}
