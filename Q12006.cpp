#include <bits/stdc++.h>
using namespace std;

char original[8][8];
char pieces[11][8][8];
int n, k;

//horizontal shift, vertical shift
char p1_shift [8][8][8][8];
char p2_shift [8][8][8][8];

bool check(int h1, int v1, int h2, int v2){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char current = '.';
            if(p1_shift[h1][v1][i][j] == '#' && p2_shift[h2][v2][i][j] == '#') return false;
            if((p1_shift[h1][v1][i][j] == '#' && p2_shift[h2][v2][i][j] == '.') || (p1_shift[h1][v1][i][j] == '.' && p2_shift[h2][v2][i][j] == '#')){
                current = '#';
            }

            if(current != original[i][j]) return false;
        }
    }
    return true;
}

bool solve(int p1, int p2){
    //Vertical or horizontal, shifted by, dimensions
    memset(p1_shift, '.', sizeof(p1_shift));
    memset(p2_shift, '.', sizeof(p2_shift));

    //Shift both vertically and horizontally
    for(int h = 0; h < n; h++){
        for(int v = 0; v < n; v++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    p1_shift[h][v][i][j] = pieces[p1][(i+v)%n][(j+h)%n];
                    p2_shift[h][v][i][j] = pieces[p2][(i+v)%n][(j+h)%n];
                }
            }
        }
    }

    //Check if valid
    for(int h1 = 0; h1 < n; h1++){
        for(int v1 = 0; v1 < n; v1++){
            for(int h2 = 0; h2 < n; h2++){
                for(int v2 = 0; v2 < n; v2++){
                    if(check(h1, v1, h2, v2)) return true;
                }
            }
        }
    }

    return false;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> k;
    
    //Input
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            original[i][j] = s[j];
        }
    }

    for(int x = 1; x <= k; x++){
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            for(int j = 0; j < n; j++){
                pieces[x][i][j] = s[j];
            }
        }
    }
    
    //Check for every combination
    for(int i = 1; i <= k; i++){
        for(int j = i+1; j <= k; j++){
            if(solve(i, j)){
                cout << i << " " << j;
            }
        }
    }
}
