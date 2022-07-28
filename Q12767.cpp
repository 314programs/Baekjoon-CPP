#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;
    
    Node(){
        val = 0;
        left = NULL;
        right = NULL;
    }
};

void remove(Node * n){
    if(n -> left){
        remove(n -> left);
    }
    if(n -> right){
        remove(n -> right);
    }
    delete n;
}

string pre_order(Node * root){
    string ans = "";
    ans += "s";

    if(root -> left){
        ans += "L";
        ans += pre_order(root -> left);
        ans += "l";
    }
    if(root -> right){
        ans += "R";
        ans += pre_order(root -> right);
        ans += "r";
    }

    ans += "e";
    return ans;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int tree_cnt, tree_size;
    cin >> tree_cnt >> tree_size;
    set<string> s;
    
    //Construct a binary tree for each case using a Node class
    while(tree_cnt--){
        vector<int> tree_item(tree_size);
        for(int i = 0; i < tree_size; i++){
            cin >> tree_item[i];
        }

        Node *root = new Node;
        root -> val = tree_item[0];

        for(int i = 1; i < tree_size; i++){
            Node *current = root;
            while(true){
                if(current -> val > tree_item[i]){
                    if(current -> left == NULL){
                        current -> left = new Node;
                        current -> left -> val = tree_item[i];
                        break;
                    }
                    else{
                        current = current -> left;
                    }
                }
                else if(current -> val < tree_item[i]){
                    if(current -> right == NULL){
                        current -> right = new Node;
                        current -> right -> val = tree_item[i];
                        break;
                    }
                    else{
                        current = current -> right;
                    }
                }
                else{
                    break;
                }
            }
        }
        //Preorder the tree and get its order in a form of string, which indicates its shape
        s.insert(pre_order(root));
        //Remove the tree
        remove(root);
    }
    cout << s.size();
}
