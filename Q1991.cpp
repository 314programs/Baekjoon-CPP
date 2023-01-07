#include <bits/stdc++.h>
using namespace std;

struct node{
    char self;
    char left_child;
    char right_child;
};

map<char, node> graph;

void preorder(char root_){
    if(root_ == '.'){
        return;
    }
    cout << root_;
    preorder(graph[root_].left_child);
    preorder(graph[root_].right_child);
}

void inorder(char root_){
    if(root_ == '.'){
        return;
    }
    inorder(graph[root_].left_child);
    cout << root_;
    inorder(graph[root_].right_child);
}

void postorder(char root_){
    if(root_ == '.'){
        return;
    }
    postorder(graph[root_].left_child);
    postorder(graph[root_].right_child);
    cout << root_ ;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int node_num;
    cin >> node_num;

    for(int i = 0; i < node_num; i++){
        char self_, left_, right_;
        cin >> self_ >> left_ >> right_;
        graph[self_] = {self_, left_, right_};
    }

    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');
    

}

