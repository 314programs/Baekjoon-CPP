#include <bits/stdc++.h>
using namespace std;

//Trie but with a counter
struct Trie{
    struct Node{
        int children[2];
        int cnt[2];
        bool valid;
        
        Node(){
            memset(children, -1, sizeof(children));
            memset(cnt, 0, sizeof(cnt));
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
        //Counts number of children
        trie[node].cnt[c] += 1;
        add(trie[node].children[c], num, bit-1);
    }

    void add(int num){
        add(root, num, 31);
    }

    int search(int node, int num, int bit, int k){
        if(bit == -1) return 0;
        //Compare with k
        int c1 = (k >> bit) & 1;
        int c2 = (num >> bit) & 1;
        int ans = 0;
        
        //k is 1, meaning options of c2 being 1 and 0 is both allowed
        if(c1 == 1){
            //Add current c2 count
            ans += trie[node].cnt[c2];
            //Change c2
            c2 = 1 - c2;
        }
        //If c2 dosen't exist
        if(trie[node].children[c2] == -1) return ans;
        //Add all other possiblities
        ans += search(trie[node].children[c2], num, bit-1, k);
        return ans;
    }

    int search(int num, int k){
        return search(root, num, 31, k);
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    Trie trie;
    int listlen, k;
    cin >> listlen >> k;

    int prefix = 0;
    trie.add(0);
    long long ans = 0;

    for(int i = 0; i < listlen; i++){
        int num;
        cin >> num;
        prefix ^= num;
        ans += trie.search(prefix, k);
        trie.add(prefix);
    }
    cout << ans << "\n";
    
}
