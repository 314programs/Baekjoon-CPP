//How did I swap x and y and spend 1 hour on this
#include <bits/stdc++.h>
using namespace std;

struct cross{
    int x, y, size_;
};

vector<cross> ans;
int height, width;

void check(vector<vector<char>> & graph, int x, int y){
    int size = 0;
    
    //Checking for cross
    while(true){
        int change = size + 1;

        if(y + change >= height || graph[y + change][x] == '.') break;
        if(y - change < 0 || graph[y - change][x] == '.') break;
        if(x + change >= width || graph[y][x + change] == '.') break;
        if(x - change < 0 || graph[y][x - change] == '.') break;

        graph[y + change][x] = 'o';
        graph[y - change][x] = 'o';
        graph[y][x + change] = 'o';
        graph[y][x - change] = 'o';

        size++;
    }
    
    if(size > 0){
        graph[y][x] = 'o';
        ans.push_back({x+1, y+1, size});
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    //Input
    cin >> height >> width;
    cin.ignore();

    vector<vector<char>> graph(height, vector<char> (width));

    for(int y = 0; y < height; y++){
        string temp;
        getline(cin, temp);
        for(int x = 0; x < width; x++){
            graph[y][x] = temp[x];
        }
    }
    
    //Checking for all crosses
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            if(graph[y][x] == '*' || graph[y][x] == 'o'){
                check(graph, x, y);
            }
        }
    }
    
    //If any * remain, answer is -1
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            if(graph[y][x] == '*'){
                cout << -1;
                return 0;
            }
        }
    }

    cout << ans.size() << "\n";
    for(auto ch: ans){
        cout << ch.y << " " << ch.x << " " << ch.size_ << "\n";
    }

}
