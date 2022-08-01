#include <bits/stdc++.h>
using namespace std;

//Trie, but instead of characters 1 and 0 are used
struct Trie{
    struct Node{
        int children[2];
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

    void add(int node, int num, int bit){
        if(bit == -1){
            trie[node].valid = true;
            return;
        }
        int c = (num >> bit) & 1;
        if(trie[node].children[c] == -1){
            int next = init();
            trie[node].children[c] = next;
        }
        add(trie[node].children[c], num, bit-1);
    }
    
    void a(int num){
        add(root, num, 31);
    }

    int query(int node, int num, int bit){
        if(bit == -1) return 0;
        int c = (num >> bit) & 1;
        c = 1-c;
        
        if(trie[node].children[c] == -1) c = 1-c;
        if(trie[node].children[c] == -1) return 0;

        int next = 0;
        if(c == 1) next = 1 << bit;
        return next | query(trie[node].children[c], num, bit-1);
    }

    int q(int num){
        return query(root, num, 31);
    }
       
};


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    int ans = 0;
    Trie trie;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        trie.a(num);
        ans = max(trie.q(num) ^ num, ans);
    }
    cout << ans;
}
