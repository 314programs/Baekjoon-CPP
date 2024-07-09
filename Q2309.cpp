#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int gnome[9];
    int total = 0;
    for(int i = 0; i < 9; i++){
        cin >> gnome[i];
        total += gnome[i];
    }

    sort(gnome, gnome+9);

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(total - gnome[i] - gnome[j] == 100){
                for(int k = 0; k < 9; k++){
                    if(k != i && k != j){
                        cout << gnome[k] << "\n";
                    }
                }
                return 0;
            }
        }
    }

}
