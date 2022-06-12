#include <bits/stdc++.h>
using namespace std;

int num_list[10] = {11,54,76,98,100,786,43,2,9,10};

int pivot(int start, int end){
    //Set pivot to middle
    int pivot_ = (start+end)/2;
    //Get value of the pivot
    int compare = num_list[pivot_];
    //Declare an index that is used to swap positions
    int change_index = start;

    swap(num_list[pivot_], num_list[end]);

    for(int i = start; i < end; i++){
        if(num_list[i] < compare){
            //Swap if it is smaller then the pivot
            //If its smaller then the pivot, it goes to the left of the pivot
            //Else it goes to the right of the pivot
            swap(num_list[i], num_list[change_index]);
            change_index++;
        }
    }

    swap(num_list[change_index], num_list[end]);
    //Return the position of the pivot
    return change_index;
}

void quick_sort(int start, int end){
    if(start < end){
        int mid = pivot(start, end);
        //Use the pivot to split and sort
        quick_sort(start, mid-1);
        quick_sort(mid+1, end);
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    quick_sort(0, 9);
    for(auto ch: num_list){
        cout << ch << " ";
    }
    cout << "\n";


}
