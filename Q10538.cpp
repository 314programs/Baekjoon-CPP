#include <bits/stdc++.h>
using namespace std;

long long mod = 2147483647;
int base = 2;

//Hashing
long long h(vector<int> & a, int begin, int end){
    long long ans = 0;
    for(int i = begin; i < end; i++){
        ans = (ans * base + a[i]) % mod;
    }
    return ans;
}

//Converting string into numbers 1 and 0
vector<int> convert(string &s){
    int s_len = s.length();
    vector<int> ans(s_len, 0);
    for(int i = 0; i < s_len; i++){
        if(s[i] == 'o') ans[i] = 1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    //Input and convert
    int height_s, width_s, height_l, width_l;
    cin >> height_s >> width_s >> height_l >> width_l;
    
    vector<vector<int>> small(height_s);
    vector<vector<int>> big(height_l);


    for(int y = 0; y < height_s; y++){
        string temp;
        cin >> temp;
        small[y] = convert(temp);
    }

    for(int y = 0; y < height_l; y++){
        string temp;
        cin >> temp;
        big[y] = convert(temp);
    }
    
    //Base values for hashing
    long long pow_width = 1;
    for(int i = 0; i < width_s-1; i++){
        pow_width = (pow_width * base) % mod;
    }

    long long base_height = (pow_width * base) % mod;
    long long pow_height = 1;
    for(int i = 0; i < height_s-1; i++){
        pow_height = (pow_height * base_height) % mod;
    }

    long long hash_small = 0;
    for(int i = 0; i < height_s; i++){
        hash_small = (hash_small * base_height + h(small[i], 0, width_s)) % mod;
    }
    
    //Hash columns
    vector<vector<long long>> hash_col(height_l, vector<long long>(width_l));
    {
        auto &d = hash_col;
        for(int i = 0; i < height_l; i++){
            d[i][0] = h(big[i], 0, width_s);
            for(int j = 1; j <= width_l - width_s; j++){
                d[i][j] = d[i][j-1] - (big[i][j-1] * pow_width) % mod;
                d[i][j] = (d[i][j] + mod) % mod;
                d[i][j] = ((d[i][j] * base) % mod + big[i][j + width_s - 1]) % mod;
            }
        }
    }
    
    //Use hash_col to hash rectangle
    vector<vector<long long>> hash_rect(height_l, vector<long long> (width_l));
    {
        auto &d = hash_rect;
        for(int j = 0; j <= width_l - width_s; j++){
            d[0][j] = 0;
            for(int i = 0; i < height_s; i++){
                d[0][j] = (d[0][j] * base_height + hash_col[i][j]) % mod;
            }
            for(int i = 1; i <= height_l - height_s; i++){
                d[i][j] = d[i-1][j] - (hash_col[i-1][j] * pow_height) % mod;
                d[i][j] = (d[i][j] + mod) % mod;
                d[i][j] = ((d[i][j] * base_height) % mod + hash_col[i + height_s-1][j]) % mod;
            }
        }
    }
    
    //Print ans
    int ans = 0;
    for(int i = 0; i <= height_l - height_s; i++){
        for(int j = 0; j <= width_l - width_s; j++){
            if(hash_rect[i][j] == hash_small) ans++;
        }
    }
    cout << ans;

}
