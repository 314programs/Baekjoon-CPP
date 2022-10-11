#include <bits/stdc++.h>
using namespace std;

int height, width, spin_num;

struct spin{
    int center_y, center_x, repeat;
};

void spin_one(spin s, vector<vector<int>> & graph){
    vector<vector<int>> temp = graph;
    for(int i = 1; i <= s.repeat; i++){
        int dimension = i;
        
        for(int y = s.center_y - dimension; y < s.center_y + dimension; y++){
            graph[y][s.center_x - dimension] = temp[y+1][s.center_x - dimension];
        }


        for(int x = s.center_x - dimension + 1; x <= s.center_x + dimension; x++){
            graph[s.center_y - dimension][x] = temp[s.center_y - dimension][x-1];
        }

        for(int y = s.center_y + dimension; y > s.center_y - dimension; y--){
            graph[y][s.center_x + dimension] = temp[y-1][s.center_x + dimension];
        }

        for(int x = s.center_x + dimension - 1; x >= s.center_x - dimension; x--){
            graph[s.center_y + dimension][x] = temp[s.center_y + dimension][x+1];
        }
    }
}

int spin_graph(vector<int> & order, vector<vector<int>> graph, vector<spin> & spins){
    for(auto ch: order){
        spin_one(spins[ch], graph);
    }

    int min_ans = 1e+9;
    for(int y = 0; y < height; y++){
        int temp = 0;
        for(int x = 0; x < width; x++){
            temp += graph[y][x];
        }
        min_ans = min(temp, min_ans);
    }
    return min_ans;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> height >> width >> spin_num;

    vector<vector<int>> graph(height, vector<int> (width));
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            cin >> graph[y][x];
        }
    }

    vector<spin> spins(spin_num);
    vector<int> p(spin_num);
    for(int i = 0; i < spin_num; i++){
        int y_, x_, r;
        cin >> y_ >> x_ >> r;
        spins[i] = {y_-1, x_-1, r};
        p[i] = i;
    }

    int ans = 1e+9;
    do{
        ans = min(spin_graph(p, graph, spins), ans);
    }
    while(next_permutation(p.begin(), p.end()));
    cout << ans;
}
