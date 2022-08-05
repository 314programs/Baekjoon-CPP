#include <bits/stdc++.h>
using namespace std;

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
        //0 or 1 for current bit?
        int c = (num >> bit) & 1;
        if(trie[node].children[c] == -1){
            int next = init();
            trie[node].children[c] = next;
        }
        add(trie[node].children[c], num, bit-1);
    }
    
    //Set total bit to 31 to match length of the string
    void add(int num){
        add(root, num, 31);
    }

    int search(int node, int num, int bit){
        if(node == -1) return false;
        int c = (num >> bit) & 1;
        //To maximise amount of bits when using XOR, different number has to be used
        c = 1-c;
        
        //If different number does not exist, revert back to original
        if(trie[node].children[c] == -1){
            c = 1-c;
        }
        //All numbers don't exist???
        if(trie[node].children[c] == -1){
            return 0;
        }

        int next = 0;
        //1 means its getting added, 0 means not
        if(c == 1) next = 1 << bit;
        //Add the rest using OR
        return next | search(trie[node].children[c], num, bit-1);
    }

    int search(int num){
        return search(root, num, 31);
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
        int listlen;
        cin >> listlen;

        int ans = 0;
        //XOR total until i
        int prefix = 0;
        //No XOR option
        trie.add(0);

        for(int i = 0; i < listlen; i++){
            int num;
            cin >> num;
            //Add the XOR to the prefix
            prefix ^= num;
            trie.add(prefix);
            //XOR here
            ans = max(trie.search(prefix) ^ prefix, ans);
        }
        cout << ans << "\n";
    }
    
}
