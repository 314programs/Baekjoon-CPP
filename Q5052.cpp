#include <bits/stdc++.h>
using namespace std;

//Good with Trie now
struct Trie{
    struct Node{
        int children[10];
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

    void add(int node, string & s, int index){
        if(index == s.length()){
            trie[node].valid = true;
            return;
        }
        int c = s[index] - '0';
        if(trie[node].children[c] == -1){
            int next = init();
            trie[node].children[c] = next;
        }
        add(trie[node].children[c], s, index+1);
    }

    void add(string & s){
        add(root, s, 0);
    }

    bool search(int node, string & s, int index){
        if(node == -1) return false;
        if(index == s.length()) return false;
        //Suffix found
        if(trie[node].valid) return true;
        int c = s[index] - '0';
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
    
    int tc;
    cin >> tc;
    while(tc--){
        Trie trie;
        int num_cnt;
        cin >> num_cnt;

        vector<string> num_list(num_cnt);
        for(int i = 0; i < num_cnt; i++){
            cin >> num_list[i];
            trie.add(num_list[i]);
        }

        string ans = "YES";
        for(int i = 0; i < num_cnt; i++){
            if(trie.search(num_list[i])) ans = "NO";
        }
        cout << ans << "\n";

    }
    
}
