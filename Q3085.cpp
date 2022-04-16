#include <bits/stdc++.h>
using namespace std;

char table[50][50];
int dimension;

int check(void){
    int maximum_count = 0;
    
    //Check row
    for(int y = 0; y < dimension; y++){
        int count = 1;
        for(int x = 0; x < dimension-1; x++){
            if(table[y][x] == table[y][x+1]){
                count += 1;
            }
            else{
                count = 1;
            }
            maximum_count = max(count, maximum_count);
        }
    }

    //Check column
    for(int x = 0; x < dimension; x++){
        int count = 1;
        for(int y = 0; y < dimension-1; y++){
            if(table[y][x] == table[y+1][x]){
                count += 1;
            }
            else{
                count = 1;
            }
            maximum_count = max(count, maximum_count);
        }
    }

    return maximum_count;

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int maximum = 0;
    cin >> dimension;

    for(int y = 0; y < dimension; y++){
        for(int x = 0; x < dimension; x++){
            cin >> table[y][x];
        }
    }

    for(int y = 0; y < dimension; y++){
        for(int x = 0; x < dimension; x++){
            //Up down
            if(y + 1 < dimension){
                swap(table[y][x], table[y+1][x]);
                maximum = max(maximum, check());
                swap(table[y][x], table[y+1][x]);
            }
            //Right left
            if(x + 1 < dimension){
                swap(table[y][x], table[y][x+1]);
                maximum = max(maximum, check());
                swap(table[y][x], table[y][x+1]);
            }
        }
    }

    cout << maximum;

}
