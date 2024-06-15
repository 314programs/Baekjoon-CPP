#include <bits/stdc++.h>
using namespace std;

int lesson_num, disks;

//Calculates how many disks can be made with current maximum length
int calc(int max_min, vector<int> & a){
    int count_ = 0;
    int disk_count = 0;
    for(int i = 0; i < lesson_num; i++){
        if(count_ + a[i] >= max_min){
            count_ = a[i];
            disk_count++;
        }
        else{
            count_ += a[i];
        }
    }

    return disk_count;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> lesson_num >> disks;

    vector<int> lessons(lesson_num);
    int total = 0;
    for(int i = 0; i < lesson_num; i++){
        cin >> lessons[i];
        total += lessons[i];
    }

    //Mid is the maximum length of the disk
    int left = 1, right = total;
    int ans = 0;
    while(left <= right){
        int mid = (left+right)/2;
        if(calc(mid, lessons) < disks){
            right = mid - 1;
        }
        else{
            ans = mid;
            left = mid + 1;
        }
    }
    
    int count_ = 0;
    int disk_count = 0;
    int max_ = 0;
  
    //Calculates maximum length from maximum
    for(int i = 0; i < lesson_num; i++){
        if(count_ + lessons[i] > ans){
            max_ = max(count_, max_);
            count_ = lessons[i];
            disk_count++;
        }
        else{
            count_ += lessons[i];
        }
    }
    max_ = max(count_, max_);
    cout << max_;

}
