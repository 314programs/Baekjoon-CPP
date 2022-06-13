#include <bits/stdc++.h>
using namespace std;

//Label the 3 places A, B, C
//All circles are placed at A in the beginning, they need to be placed at C at the end
void solve(int disks, int from, int to){
    if(disks == 0) return;
    //Move the top disks from A to B
    solve(disks-1, from, 6-from-to);
    //Move current disk to C
    cout << from << " " << to << "\n";
    //Move the other disks from B to C
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
