//Intro to segment tree
#include <bits/stdc++.h>
using namespace std;

void init(vector<int> &tr, vector<int> & nodes, int node, int start, int end){
    //1 node
    if(start == end){
        tr[node] = nodes[start];
    }
    else{
        //Divide into 2 sections by half
        init(tr, nodes, node*2, start, (start+end)/2);
        init(tr, nodes, (node*2)+1, ((start+end)/2) + 1, end);
        //Minimum of current section
        tr[node] = min(tr[node*2], tr[node*2 + 1]);
    }
}

int query(vector<int> &tr, int node, int start, int end, int i, int j){
    //Over the range
    if(end < i || start > j) return -1;
    //Inside the range
    if(start >= i && end <= j) return tr[node];
    
    //Divide by half to find the suitable range
    int n1 = query(tr, node*2, start, (start+end)/2, i, j);
    int n2 = query(tr, (node*2)+1, ((start+end)/2) + 1, end, i, j);
    //Out of range for one value, one has to be within value always
    if(n1 == -1) return n2;
    if(n2 == -1) return n1;
    //Both has been found
    else{
        return min(n1, n2);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> nodes(n);
    //Tree height
    int h = (int)ceil(log2(n));
    //Make a big enough tree
    int tree_size = (1 << (h+1));
    vector<int> tr(tree_size);

    for(int i = 0; i < n; i++){
        cin >> nodes[i];
    }
    init(tr, nodes, 1, 0, n-1);
    
    //Running query
    for(int i = 0; i < m; i++){
        int s, e;
        cin >> s >> e;
        cout << query(tr, 1, 0, n-1, s-1, e-1) << "\n";
    }

}
