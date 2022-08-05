#include <bits/stdc++.h>
using namespace std;

bool compare(string u, string v){
    if(u.length() != v.length()){
        return u.length() > v.length();
    }
    return u < v;
}

int score[9] = {0, 0, 0, 1, 1, 2, 3, 5, 11};
char graph[4][4];
int visited[4][4];
vector<string> s_list;

int dx[8] = {0,0,1,-1,1,1,-1,-1};
int dy[8] = {1,-1,0,0,1,-1,1,-1};

struct Trie{
    struct Node{
        int children[26];
        bool valid;
        
        Node(){
            memset(children, -1, sizeof(children));
            valid = false;
        }
    };

    vector<Node> trie;
    int root;
    
    int init(){
        Node x;
        trie.push_back(x);
        return trie.size() - 1;
    }

    Trie(){
        root = init();
    }
    
    //Use DFS to find all possible strings and add them to a trie
    void add(int node, int start_x, int start_y, int depth){
        if(depth == 8) return;
        for(int i = 0; i < 8; i++){
            int ny = start_y + dy[i];
            int nx = start_x + dx[i];
            if(ny >= 0 && ny < 4 && nx >= 0 && nx < 4 && visited[ny][nx] == -1){
                visited[ny][nx] = 0;
                int c = graph[ny][nx] - 'A';
                if(trie[node].children[c] == -1){
                    int new_child = init();
                    trie[node].children[c] = new_child;
                }
                add(trie[node].children[c], nx, ny, depth+1);
                visited[ny][nx] = -1;
            }
        }
    }
      
    //Make sure to mark the beginning
    void add(int start_x, int start_y){
        int c = graph[start_y][start_x] - 'A';
        if(trie[root].children[c] == -1){
            int next = init();
            trie[root].children[c] = next;
        }
        int child = trie[root].children[c];

        visited[start_y][start_x] = 0;
        add(child, start_x, start_y, 0);
        visited[start_y][start_x] = -1;
    }

    bool search(int node, string & s, int index){
        if(node == -1) return false;
        //Found string
        if(index == s.length()) return true;
        int c = s[index] - 'A';
        return search(trie[node].children[c], s, index+1);
    }

    bool search(string & s){
        return search(root, s, 0);
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int word_cnt;
    cin >> word_cnt;
    vector<string> words(word_cnt);

    for(int i = 0; i < word_cnt; i++){
        cin >> words[i];
    }
    sort(words.begin(), words.end(), compare);

    cin.ignore();
    int board_cnt;
    cin >> board_cnt;
    memset(visited, -1, sizeof(visited));

    while(board_cnt--){
        //Add board to the trie
        Trie trie;
        
        cin.ignore();
        for(int y = 0; y < 4; y++){
            string temp;
            cin >> temp;
            for(int x = 0; x < 4; x++){
                graph[y][x] = temp[x];
            }
        }

        for(int y = 0; y < 4; y++){
            for(int x = 0; x < 4; x++){
                trie.add(x, y);
            }
        }

        int total_score = 0;
        string longest = "-1";
        int words_found = 0;
        
        //Search for words
        for(auto s: words){
            if(trie.search(s)){
                total_score += score[s.length()];
                words_found++;
                if(longest == "-1"){
                    longest = s;
                }
            }
        }
        
        cout << total_score << " " << longest << " " << words_found << "\n";

    }
    
}
