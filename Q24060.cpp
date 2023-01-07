//I forgot on merge sort...
//I rely on merge()...

#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

int ans = -1;
int k;
int save_cnt = 0;

void mergesort(vector<int> &a, int l, int r){
    int temp[r-l+1];
    int mid = (l+r)/2;
    int i = l, j = mid+1;
    int cnt = 0;

    while(i <= mid && j <= r){
        save_cnt++;
        if(a[i] <= a[j]){
            if(save_cnt == k) ans = a[i];
            temp[cnt++] = a[i++];
        }
        else{
            if(save_cnt == k) ans = a[j];
            temp[cnt++] = a[j++];
        }
    }

    while(i <= mid){
        save_cnt++;
        if(save_cnt == k) ans = a[i];
        temp[cnt++] = a[i++];
    }
    while(j <= r){
        save_cnt++;
        if(save_cnt == k) ans = a[j];
        temp[cnt++] = a[j++];
    }


    for(int i = l; i <= r; i++){
        a[i] = temp[i-l]; 
    }

}

void merge(vector<int> &a, int l, int r){
    if(l == r){
        return;
    }
    int mid = (l+r)/2;
    merge(a, l, mid);
    merge(a, mid+1, r);
    mergesort(a, l, r);
}

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int n;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    merge(a, 0, n-1);
    cout << ans;

}
