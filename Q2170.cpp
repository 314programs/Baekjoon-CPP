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
        lines[i] = make_pair(s, 1);
        lines[i+1] = make_pair(e, -1);
    }

    sort(lines.begin(), lines.end());
    int ans = 0;
    int cnt = 0;
    int last = 0;
    //Sweeping to find start and end of the line, and getting its length
    for(auto &ch: lines){
        if(ch.second == 1 && cnt == 0){
            last = ch.first;
        }
        cnt += ch.second;
        if(ch.second == -1 && cnt == 0){
            ans += ch.first - last;
        }
    }

    cout << ans;

}
