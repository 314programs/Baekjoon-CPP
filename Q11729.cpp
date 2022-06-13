#include <bits/stdc++.h>
using namespace std;

void solve(int disks, int from, int to){
    if(disks == 0) return;
    //Move the top disks first
    solve(disks-1, from, 6-from-to);
    cout << from << " " << to << "\n";
    //Move back the top disks
    solve(disks-1, 6-from-to, to);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int disk_num;
    cin >> disk_num;

    long long temp = pow(2, disk_num) - 1;
    cout << temp << "\n";
    solve(disk_num, 1, 3);
}
