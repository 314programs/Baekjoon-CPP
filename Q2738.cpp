#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int x, y;
    cin >> x >> y;
    int graph1[y][x];
    int graph2[y][x];

    for(int y_ = 0; y_ < y; y_++){
        for(int x_ = 0; x_ < x; x_++){
            cin >> graph1[y_][x_];
        }
    }

    for(int y_ = 0; y_ < y; y_++){
        for(int x_ = 0; x_ < x; x_++){
            cin >> graph2[y_][x_];
        }
    }

    for(int y_ = 0; y_ < y; y_++){
        for(int x_ = 0; x_ < x; x_++){
            cout << graph1[y_][x_] + graph2[y_][x_];
            if(x_ < x-1) cout << " ";
        }
        cout << "\n";
    }


}
