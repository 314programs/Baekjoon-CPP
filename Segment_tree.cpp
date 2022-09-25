#include <bits/stdc++.h>
using namespace std;

void init(vector<int> &tree, vector<int> &a, int node, int start, int end){
    //Singular section change
    if(start == end){
        tree[node] = a[start];
    }
    else{
        //Can be divded into 2 sections, half and half
        init(tree, a, node*2, start, (start+end)/2);
        init(tree, a, (node*2)+1, ((start+end)/2) + 1, end);
        //Get minimum
        tree[node] = min(tree[(node*2)+1], tree[node*2]);
    }
}

void update(vector<int> &tree, int change_i, int change_num, int node, int start, int end){
    //Out of range
    if(start > change_i || end < change_i) return;
    //Found node to update
    if(start == end){
        tree[node] = change_num;
        return;
    }
    //Divide in half till it finds node to update
    update(tree, change_i, change_num, node*2, start, (start+end)/2);
    update(tree, change_i, change_num, (node*2)+1, ((start+end)/2)+1, end);
    //Update current node since its child has been upaded
    tree[node] = min(tree[node*2], tree[(node*2)+1]);
}

int query(vector<int> &tree, int node, int start, int end, int i, int j){
    //Out of range
    if(start > j || end < i) return -1;
    //Inside range
    if(start >= i && end <= j) return tree[node];
    
    //Divide by half to search
    int n1 = query(tree, node*2, start, (start+end)/2, i, j);
    int n2 = query(tree, (node*2)+1, ((start+end)/2)+1, end, i, j);
    
    //At least 1 of divided section has to return a value
    if(n1 == -1) return n2;
    else if(n2 == -1) return n1;
    //Get minimum when both has value 
    else return min(n1, n2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    //Calculate tree size using log and bitmasking
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));
    vector<int> tree(tree_size);
  
    //Initialise tree
    init(tree, a, 1, 0, n-1);

    int m;
    cin >> m;
    while(m--){
        int c, i, j;
        cin >> c >> i >> j;
        //Update or query?
        if(c == 1){
            update(tree, i-1, j, 1, 0, n-1);
        }
        else{
            cout << query(tree, 1, 0, n-1, i-1, j-1) << "\n";
        }
    }
}
