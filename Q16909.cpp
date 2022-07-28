#include <bits/stdc++.h>
using namespace std;

long long calc(long long n){
    return n*(n+1)/2;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int list_len;
    cin >> list_len;
    vector<int> num_list(list_len+1);

    vector<int> left_g(list_len+1, 0);
    vector<int> right_g(list_len+1, list_len+1);
    vector<int> left_s(list_len+1, 0);
    vector<int> right_s(list_len+1, list_len+1);
  
    //Start with 1 for convinience in calculations later
    for(int i = 1; i <= list_len; i++){
        cin >> num_list[i];
    }

    //RIGHT
    {
        stack<pair<int, int>> stack_g, stack_s;
        stack_g.push(make_pair(1, num_list[1]));
        stack_s.push(make_pair(1, num_list[1]));
        
        //Get indexes of where the current number stops being the greatest/smallest
        //These are divided into left and right
        for(int i = 2; i <= list_len; i++){
            while(!stack_g.empty() && num_list[i] >= stack_g.top().second){
                right_g[stack_g.top().first] = i;
                stack_g.pop();
            }
            stack_g.push(make_pair(i, num_list[i]));

            while(!stack_s.empty() && num_list[i] <= stack_s.top().second){
                right_s[stack_s.top().first] = i;
                stack_s.pop();
            }
            stack_s.push(make_pair(i, num_list[i]));
        }
    }

    //LEFT
    {
        stack<pair<int, int>> stack_g, stack_s;
        stack_g.push(make_pair(list_len, num_list[list_len]));
        stack_s.push(make_pair(list_len, num_list[list_len]));

        for(int i = list_len-1; i >= 1; i--){
            while(!stack_g.empty() && num_list[i] > stack_g.top().second){
                left_g[stack_g.top().first] = i;
                stack_g.pop();
            }
            stack_g.push(make_pair(i, num_list[i]));

            while(!stack_s.empty() && num_list[i] < stack_s.top().second){
                left_s[stack_s.top().first] = i;
                stack_s.pop();
            }
            stack_s.push(make_pair(i, num_list[i]));
        }
    }

    long long ans = 0;
    //Use the left and right indexes to calculate how many sub-groups can be produced with the current number being:
    //Maximum +
    //Minimum -
    for(int i = 1; i <= list_len; i++){
        int l = min(i, left_g[i]+1);
        int r = max(i, right_g[i]-1);
        long long len = r - l + 1;
        ans += (calc(len) - calc(r-i) - calc(i-l)) * num_list[i];
    }

    for(int i = 1; i <= list_len; i++){
        int l = min(i, left_s[i]+1);
        int r = max(i, right_s[i]-1);
        long long len = r - l + 1;
        ans -= (calc(len) - calc(r-i) - calc(i-l)) * num_list[i];
    }
    cout << ans;

}
