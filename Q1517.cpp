#include <bits/stdc++.h>
using namespace std;

long long merge(int start, int end, vector<long long> & num_list){
    int mid = (start+end)/2;
    long long total = 0;
    int i = start, j = mid + 1;

    vector<long long> temp;

    while(i <= mid && j <= end){
        if(num_list[i] > num_list[j]){
            total += mid - i + 1;
            temp.push_back(num_list[j++]);
        }
        else{
            temp.push_back(num_list[i++]);
        }
    }

    while(i <= mid) temp.push_back(num_list[i++]);
    while(j <= end) temp.push_back(num_list[j++]);

    int idx = start;
    for(auto ch: temp){
        num_list[idx++] = ch;
    }

    return total;

}

long long merge_sort(int start, int end, vector<long long> & num_list){
    if(start == end) return 0;
    int mid = (start+end)/2;

    long long total = 0;
    total += merge_sort(start, mid, num_list);
    total += merge_sort(mid+1, end, num_list);
    total += merge(start, end, num_list);
    return total;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int list_len;
    cin >> list_len;

    vector<long long> numlist(list_len);
    for(int i = 0; i < list_len; i++) cin >> numlist[i];

    cout << merge_sort(0, list_len-1, numlist);
}
