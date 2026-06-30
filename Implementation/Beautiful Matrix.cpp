#include <bits/stdc++.h>
using namespace std;
// Beautiful Matrix - Codeforces 263A
// Find number of moves to put 5 in the center of 5x5 matrix
int main(){
    int a[5][5];
    int r, c;
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++){
            cin>>a[i][j];
            if(a[i][j]==5){r=i;c=j;}
        }
    cout << abs(r-2)+abs(c-2) << "\n";
}
