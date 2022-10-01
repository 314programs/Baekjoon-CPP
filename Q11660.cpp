#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int a[1025][1025];
int s[1025][1025];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), std::cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            //Removed s[i-1][j-1], since it was added twice
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
        }
    }

    while(m--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        //Trim the edge, -1 to not cut the main area
        cout << s[x2][y2] - s[x2][y1-1] - s[x1-1][y2] + s[x1-1][y1-1] << "\n";
    }

}
