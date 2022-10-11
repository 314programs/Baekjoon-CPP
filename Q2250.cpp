#include <bits/stdc++.h>
using namespace std;

struct node{
    int left_child, right_child;
    int order, depth;
};

node graph[10001];
int parent_[10001];
int order = 0;

void inorder(int node, int depth){
    if(node == -1) return;
    inorder(graph[node].left_child, depth+1);
    graph[node].depth = depth;
    graph[node].order = ++order;
    inorder(graph[node].right_child, depth+1);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int node_num;
    cin >> node_num;

    memset(parent_, -1, sizeof(parent_));

    for(int i = 0; i < node_num; i++){
        int parent, left, right;
        cin >> parent >> left >> right;
        graph[parent] = {left, right};
        if(left != -1) parent_[left] += 1;
        if(right != -1) parent_[right] += 1;
    }

    int root = -1;
    for(int i = 1; i <= node_num; i++){
        if(parent_[i] == -1){
            root = i;
        }
    }

    inorder(root, 1);

    int right[10001];
    int left[10001];
    memset(right, 0, sizeof(right));
    memset(left, 10001, sizeof(left));
    int max_depth = 0;

    for(int i = 1; i <= node_num; i++){
        left[graph[i].depth] = min(left[graph[i].depth], graph[i].order);
        right[graph[i].depth] = max(right[graph[i].depth], graph[i].order);
        max_depth = max(max_depth, graph[i].depth);
    }

    int max_width = -1;
    int level_ = 0;

    for(int i = 1; i <= max_depth; i++){
        if(right[i] - left[i] > max_width){
            max_width = right[i] - left[i];
            level_ = i;
        }
    }
    cout << level_ << " " << max_width + 1;
}

