//I have no idea how this works... I will comment more when I learn more
#include <bits/stdc++.h>
using namespace std;

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
            if(trie[node].len > 0){
                matches.push_back(make_pair(i-trie[node].len + 1, -1));
                matches.push_back(make_pair(i, 1));
            }
        }

        int ans = 0;
        sort(matches.begin(), matches.end());
        int start = 0;
        int open = 0;

        //Sweeping algorithm that I have to learn soon
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
    ac.make();
    cout << n - ac.solve(s) << "\n";
}
