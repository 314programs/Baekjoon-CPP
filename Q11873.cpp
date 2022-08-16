//Similar to finding rectangles in histogram question...
#include <bits/stdc++.h>
using namespace std;

int graph[1000][1000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while(true){
        int h, w;
        cin >> h >> w;

        if(h == 0) break;

        for(int y = 0; y < h; y++){
            for(int x = 0; x < w; x++){
                cin >> graph[y][x];
            }
        }
        
        //Make list of height for each y
        vector<int> current_height(w, 0);
        int ans = 0;

        for(int y = 0; y < h; y++){
            for(int x = 0; x < w; x++){
                if(graph[y][x] == 0) current_height[x] = 0;
                else current_height[x] += 1;
            }
            
            //Use stack to find biggest rectangle
            stack<int> s;
            for(int i = 0; i < w; i++){
                while(!s.empty() && current_height[s.top()] > current_height[i]){
                    int height = current_height[s.top()];
                    s.pop();

                    int width = i;
                    if(!s.empty()) width = i - s.top() - 1;
                    ans = max(ans, height * width);
                }
                s.push(i);
            }

            while(!s.empty()){
                int height = current_height[s.top()];
                s.pop();

                int width = w;
                if(!s.empty()) width = width - s.top() - 1;
                ans = max(ans, height * width);
            }
        }

        cout << ans << "\n";

    }

}
