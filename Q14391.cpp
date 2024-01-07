#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int height, width;
    cin >> height >> width;

    int graph[4][4];
    int max_sum = 0;

    for(int y = 0; y < height; y++){
        string temp;
        cin >> temp;
        for(int x = 0; x < width; x++){
            graph[y][x] = temp[x]-'0';
        }
    }

    for(int bit_ = 0; bit_ < (1 << height*width); bit_++){
        int temp_graph[4][4];
        int temp_sum = 0;
        
        //All possibilities explored by bitmasking
        for(int i = 0; i < height*width; i++){
            if(bit_&(1 << i)){
                //1 = vertical
                temp_graph[i/width][i%width] = 1;
            }
            else{
                //0 = horizontal
                temp_graph[i/width][i%width] = 0;
            }
        }

        //Vertical check
        for(int x = 0; x < width; x++){
            string temp_num = "";
            for(int y = 0; y < height; y++){
                if(temp_graph[y][x] == 1){
                    temp_num += graph[y][x] + '0';
                }
                else{
                    if(temp_num != ""){
                        temp_sum += stoi(temp_num);
                    }
                    temp_num = "";
                }
            }
            if(temp_num != ""){
                temp_sum += stoi(temp_num);
            }
        }

        //Horizontal check
        for(int y = 0; y < height; y++){
            string temp_num = "";
            for(int x = 0; x < width; x++){
                if(temp_graph[y][x] == 0){
                    temp_num += graph[y][x] + '0';
                }
                else{
                    if(temp_num != ""){
                        temp_sum += stoi(temp_num);
                    }
                    temp_num = "";
                }
            }
            if(temp_num != ""){
                temp_sum += stoi(temp_num);
            }
        }

        max_sum = max(temp_sum, max_sum);

    }

    cout << max_sum;

    


}

