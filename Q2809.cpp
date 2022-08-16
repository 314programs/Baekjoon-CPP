//May make more changes later on
#include <bits/stdc++.h>
using namespace std;

//Aho_corasick structure
struct Aho_cora{
    struct Node{
        map<int, int> children;
        int len;
        int pi;

        Node(){
            pi = -1;
            len = 0;
        }
    };
    
    //Aho corasick = Trie + KMP
    vector<Node> trie;
    int root;

    int init(){
        Node x;
        trie.push_back(x);
        return trie.size() - 1;
    }

    Aho_cora(){
        root = init();
    }

    void add(int node, string & s, int index){
        if(index == s.size()){
            //Save length of the words
            trie[node].len = index;
            return;
        }
        int c = s[index] - 'a';
        if(trie[node].children.count(c) == 0){
            int next = init();
            trie[node].children[c] = next;
        }
        add(trie[node].children[c], s, index+1);
    }

    void add(string & s){
        add(root, s, 0);
    }
    
    //Getting all fail values of node using BFS
    void make(){
        queue<int> q;
        trie[root].pi = root;
        q.push(root);

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            for(int i = 0; i < 26; i++){
                if(trie[cur].children.count(i) == 0) continue;
                int next = trie[cur].children[i];

                if(cur == root){
                    trie[next].pi = root;
                }
                else{
                    int x = trie[cur].pi;
                    while(x != root && trie[x].children.count(i) == 0){
                        x = trie[x].pi;
                    }
                    if(trie[x].children.count(i) != 0){
                        x = trie[x].children[i];
                    }
                    trie[next].pi = x;
                }

                int pi = trie[next].pi;
                trie[next].len = max(trie[next].len, trie[pi].len);
                q.push(next);
            }
        }
    }
    
    //Function for finding the substring
    int next(int node, char ch){
        int c = ch - 'a';
        while(node != root && trie[node].children.count(c) == 0){
            node = trie[node].pi;
        }
        if(trie[node].children.count(c) > 0){
            node = trie[node].children[c];
        }
        return node;
    }

    int solve(string &s){
        int node = root;
        vector<pair<int, int>> matches;
        for(int i = 0; i < s.size(); i++){
            node = next(node, s[i]);
            //Push back start and ending index to calculate length with
            if(trie[node].len > 0){
                matches.push_back(make_pair(i-trie[node].len + 1, -1));
                matches.push_back(make_pair(i, 1));
            }
        }

        int ans = 0;
        sort(matches.begin(), matches.end());
        int start = 0;
        int open = 0;

        //Sweeping algorithm that calculates the total sum of lines with overlap
        for(auto &p : matches){
            if(p.second == -1){
                if(open == 0) start = p.first;
                open += 1;
            }
            else{
                open -= 1;
                if(open == 0) ans += p.first - start + 1;
            }
        }
        return ans;
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    Aho_cora ac;
    int n;
    cin >> n;

    string s;
    cin >> s;

    int tile_cnt;
    cin >> tile_cnt;
    for(int i = 0; i < tile_cnt; i++){
        string temp;
        cin >> temp;
        ac.add(temp);
    }
    //Finding all substrings inside the list
    ac.make();
    //Since we found the substrings inside the list, subtract it from the length of the string to get answer
    cout << n - ac.solve(s) << "\n";
}
