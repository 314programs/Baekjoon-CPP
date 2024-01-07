#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int line_cnt;
    cin >> line_cnt;

    vector<pair<int, int>> lines(line_cnt*2);
    for(int i = 0; i < line_cnt*2; i+= 2){
        int s, e;
        cin >> s >> e;
        //Add one when new line starts, subtract 1 when line ends
        lines[i] = make_pair(s, 1);
        lines[i+1] = make_pair(e, -1);
    }
    
    //Sort to make sweeping alogrithm
    sort(lines.begin(), lines.end());
    int ans = 0;
    int cnt = 0;
    for(auto &ch: lines){
        cnt += ch.second;
        ans = max(ans, cnt);
    }

    cout << ans;

}
