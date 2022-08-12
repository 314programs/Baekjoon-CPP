//This one is using char instead of int
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
