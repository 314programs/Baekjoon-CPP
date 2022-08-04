#include <bits/stdc++.h>
using namespace std;

//Basic Trie
struct Node{
    int children[4];
    int pi;
    bool valid;

    Node(){
        memset(children, -1, sizeof(children));
        valid = false;
        pi = -1;
    }
};

vector<Node> trie;

//Uses only ACGT instead of alphabets
int val(char ch){
    if(ch == 'A') return 0;
    else if(ch == 'C') return 1;
    else if(ch == 'G') return 2;
    else if(ch == 'T') return 3;
    else return 4;
}

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
    int c = val(s[index]);
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
	
    int tc;
    cin >> tc;

    while(tc--){
        trie.clear();
        int root = init();
        int s_len, p_len;
        cin >> s_len >> p_len;

        string s, p;
        cin >> s >> p;
        
        //Make all mutations
        vector<string> a;
        for(int i = 0; i < p_len; i++){
            for(int j = i; j < p_len; j++){
                string p2 = p;
                reverse(p2.begin() + i, p2.begin() + j+1);
                a.push_back(p2);
            }
        }

        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());

        for(auto str_ : a){
            add(root, str_, 0);
        }

        queue<int> q;
        trie[root].pi = root;
        q.push(root);

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int next = trie[cur].children[i];
                if(next == -1) continue;

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

        int node = root;
        int found = 0;

        for(int i = 0; i < s.size(); i++){
            int c = val(s[i]);
            while(node != root && trie[node].children[c] == -1){
                node = trie[node].pi;
            }
            if(trie[node].children[c] != -1){
                node = trie[node].children[c];
            }
            if(trie[node].valid){
                //How many found?
                found++;
            }
        }

        cout << found << "\n";
    }
    

}
