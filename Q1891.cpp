//Got this one wrong cause I kept using int instead of long long

#include <bits/stdc++.h>
using namespace std;

string num;
int digits;
long long dimension;

struct coord{
    long long x;
    long long y;
};

map<int, coord> dict;

coord find_coord(int index_, coord current_pos){
    if(index_ == digits) return current_pos;
    int current_num = num[index_] - '0';
    coord next_coord = dict[current_num];

    current_pos.x += next_coord.x * pow(2, digits - index_ - 1);
    current_pos.y += next_coord.y * pow(2, digits - index_ - 1);

    current_pos = find_coord(index_+1, current_pos);
    return current_pos;
}

void value_coord(long long x_, long long y_, int index_){
    if(index_ == digits) return;
    long long half = pow(2, digits - index_ - 1);

    if(x_ < half && y_ < half){
        cout << "2";
        value_coord(x_, y_, index_+1);
    }
    else if(x_ >= half && y_ < half){
        cout << "1";
        value_coord(x_- half, y_, index_+1);
    }
    else if(x_ < half && y_ >= half){
        cout << "3";
        value_coord(x_, y_- half, index_+1);
    }
    else if(x_ >= half && y_ >= half){
        cout << "4";
        value_coord(x_ - half, y_ - half, index_+1);
    }

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> digits >> num;
    dimension = pow(2, digits);

    long long x_move, y_move;
    cin >> x_move >> y_move;

    dict.insert(pair<int, coord> (2, {0, 0}));
    dict.insert(pair<int, coord> (1, {1, 0}));
    dict.insert(pair<int, coord> (3, {0, 1}));
    dict.insert(pair<int, coord> (4, {1, 1}));
    
    coord current_pos = find_coord(0, {0, 0}); 
    current_pos.x += x_move;
    current_pos.y -= y_move;


    if(current_pos.x >= dimension || current_pos.x < 0 || current_pos.y >= dimension || current_pos.y < 0){
        cout << -1; 
        return 0;
    }

    value_coord(current_pos.x, current_pos.y, 0);

}
