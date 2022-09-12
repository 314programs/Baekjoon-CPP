#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    //Only loops till !9...
    string ans = "123456780";
    string s = "";
    for(int i = 0; i < 9; i++){
        char c;
        cin >> c;
        s += c;
    }

    queue<pair<string, int>> q;
    q.push(make_pair(s, 0));
    
    //Save memory
    set<string> m;
    m.insert(s);
    int dist = -1;

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    
    //New utility of BFS..!
    while(!q.empty()){
        auto current = q.front();
        string current_s = current.first;
        q.pop();

        if(current_s == ans){
            dist = current.second;
            break; 
        }

        int zero_pos = current_s.find("0");
        //Convert position to 3x3 for swapping
        int ix = zero_pos%3;
        int iy = zero_pos/3;

        for(int i = 0; i < 4; i++){
            int nx = ix + dx[i];
            int ny = iy + dy[i];
            if(0 <= nx && nx <= 2 && 0 <= ny && ny <= 2){
                //Convert back
                int swap_pos = nx + ny*3;
                string n_s = current_s;
                swap(n_s[zero_pos], n_s[swap_pos]);
                if(m.find(n_s) == m.end()){
                    m.insert(n_s);
                    q.push(make_pair(n_s, current.second+1));
                }
            }
        }
    }
    cout << dist;
}
