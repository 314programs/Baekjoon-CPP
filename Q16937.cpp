#include <bits/stdc++.h>
using namespace std;

int paper[100][100];
int paper_width, paper_height;

struct sticker{
    int height, width;
};

int calc(sticker u, sticker v){
    int h_1 = u.height, h_2 = v.height;
    int w_1 = u.width, w_2 = v.width;
    
    //Switch width and height for each sticker to get all possibilities
    for(int rot_1 = 0; rot_1 < 2; rot_1++){
        for(int rot_2 = 0; rot_2 < 2; rot_2++){
            if(w_1 + w_2 <= paper_width && max(h_1, h_2) <= paper_height){
                return (h_1 * w_1) + (h_2 * w_2);
            }
            if(h_1 + h_2 <= paper_height && max(w_1, w_2) <= paper_width){
                return (h_1 * w_1) + (h_2 * w_2);
            }
            swap(h_1, w_1);
        }
        swap(h_2, w_2);
    }

    return -1;
}   


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> paper_height >> paper_width;

    int sticker_num;
    cin >> sticker_num;

    vector<sticker> stickers(sticker_num);
    for(int i = 0; i < sticker_num;){
        int h, w;
        cin >> h >> w;
        stickers[i++] = {h, w};
    }
    
    int area = 0;
    //Trying out all combinations
    for(int i = 0; i < sticker_num-1; i++){
        for(int j = i+1; j < sticker_num; j++){
            area = max(area, calc(stickers[i], stickers[j]));
        }
    }
    cout << area;
}
