#include <bits/stdc++.h>
using namespace std;

int height, width;
int start_[50][50];
int end_[50][50];

void convert(int x, int y){
    //Inverting 3*3 spaces
    for(int y_ = y; y_ <= y + 2; y_ ++){
        for(int x_ = x; x_ <= x + 2; x_++){
            start_[y_][x_] = !start_[y_][x_];
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> height >> width;
    cin.ignore();
    
    //Input 2 graphs
    for(int y = 0; y < height; y++){
        string temp;
        getline(cin, temp);
        for(int x = 0; x < width; x++){
            start_[y][x] = temp[x] - '0';
        }
    }

    for(int y = 0; y < height; y++){
        string temp;
        getline(cin, temp);
        for(int x = 0; x < width; x++){
            end_[y][x] = temp[x] - '0';
        }
    }
    
    //Convert when there is something different
    int ans = 0;
    for(int y = 0; y < height - 2; y++){
        for(int x = 0; x < width - 2; x++){
            if(start_[y][x] != end_[y][x]){
                convert(x, y);
                ans += 1;
            }
        }
    }
    
    //If there is a difference, change ans to -1
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            if(start_[y][x] != end_[y][x]) ans = -1;
        }
    }

    cout << ans;
}
