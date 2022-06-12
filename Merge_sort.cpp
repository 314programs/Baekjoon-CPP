#include <bits/stdc++.h>
using namespace std;

int num_list[10] = {11,54,76,98,100,786,43,2,9,10};

void merge(int start, int end){
    //Temp list to keep values
    int temp[end-start];
    int mid = (start+end)/2;
    //Left side: i-mid
    //Right side:: mid+1-end
    int i = start, j = mid+1, k = 0;
    
    //Add in smaller number from left or right side
    while(i <= mid && j <= end){
        if(num_list[i] <= num_list[j]) temp[k++] = num_list[i++];
        else temp[k++] = num_list[j++];
    }
    
    //Add in the remaining numbers
    while(i <= mid) temp[k++] = num_list[i++];
    while(j <= end) temp[k++] = num_list[j++];

    for(int r = start; r <= end; r++){
        num_list[r] = temp[r-start];
    }

}

void merge_sort(int start, int end){
    if(start == end){
        return;
    }
    //Seperate the list into 2 pieces, sort them and merge them back
    int mid = (start+end)/2;
    merge_sort(start, mid);
    merge_sort(mid+1, end);
    merge(start, end);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    merge_sort(0, 9);
    for(auto ch: num_list){
        cout << ch << " ";
    }
    cout << "\n";


}
