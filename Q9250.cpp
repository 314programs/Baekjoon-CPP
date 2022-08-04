#include <bits/stdc++.h>
using namespace std;

//Aho-corasick... combination between trie and kmp
//Constructing trie first
struct Node{
    int children[26];
    int pi;
    bool valid;

    Node(){
        memset(children, -1, sizeof(children));
        valid = false;
        pi = -1;
    }
};

vector<Node> trie;

int init(){
    Node x;
    trie.push_back(x);
    return trie.size() - 1;
}

void add(int node, string & s, int index){
    if(index == s.size()){
        trie[node].valid = true;
        return;
    }
    int c = s[index] - 'a';
    if(trie[node].children[c] == -1){
        int next = init();
        trie[node].children[c] = next;
    }
    add(trie[node].children[c], s, index+1);
}  

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
	
    int root = init();
    int n;
    cin >> n;
    
    //Add all substring into trie
    vector<string> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        add(root, a[i], 0);
    }

    queue<int> q;
    trie[root].pi = root;
    q.push(root);
    
    //Use BFS to find fail value for each node
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i = 0; i < 26; i++){
            int next = trie[cur].children[i];
            if(next == -1) continue;
            
            //KMP here
            if(cur == root){
                trie[next].pi = root;
            }
            else{
                int x = trie[cur].pi;
                while(x != root && trie[x].children[i] == -1){
                    x = trie[x].pi;
                }
                if(trie[x].children[i] != -1) {
                    x = trie[x].children[i];
                }
                trie[next].pi = x;
            }
            int pi = trie[next].pi;
            trie[next].valid |= trie[pi].valid;
            q.push(next);
        }

    }

    int m;
    cin >> m;
    while(m--){
        string s;
        cin >> s;
        int node = root;
        bool ok = false; 
        
        //Searching through Trie using fail value (KMP)
        for(int i = 0; i < s.size(); i++){
            int c = s[i] - 'a';
            while(node != root && trie[node].children[c] == -1){
                node = trie[node].pi;
            }
            if(trie[node].children[c] != -1){
                node = trie[node].children[c];
            }
            //Substring found
            if(trie[node].valid){
                ok = true;
            }
        }

        cout << (ok ? "YES":"NO") << "\n";

    }

}
