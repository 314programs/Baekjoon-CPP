#include <bits/stdc++.h>
using namespace std;

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

    void add(int node, string &s, int index){
        if(index == s.size()){
            trie[node].valid = true;
            return;
        }
        int c = s[index] - 'a';
        if(trie[node].children[c] == -1){
            int next = init();
            trie[node].children[c] = next;
        }
        int child = trie[node].children[c];
        add(child, s, index+1);
    }

    void push(string & s){
        add(root, s, 0);
    }

    bool search(int node, string &s, int index){
        if(node == -1) return false;
        if(index == s.length()) return true;
        int c = s[index] - 'a';
        int child = trie[node].children[c];
        return search(child, s, index+1);
    }

    bool search_node(string & s){
        return search(root, s, 0);
    }
};


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    Trie trie;
    while(n--){
        string temp;
        cin >> temp;
        trie.push(temp);
    }

    int ans = 0;
    while(m--){
        string temp;
        cin >> temp;
        if(trie.search_node(temp)){
            ans++;
        }
    }
    cout << ans;
    
}
