#include <bits/stdc++.h>
using namespace std;
// Two Pointers - Find pair with given sum in sorted array
int main(){
    int n,target; cin>>n>>target;
    vector<int> a(n);
    for(auto &x:a) cin>>x;
    sort(a.begin(),a.end());
    int l=0,r=n-1;
    while(l<r){
        int s=a[l]+a[r];
        if(s==target){ cout<<l<<" "<<r<<"\n"; return 0; }
        else if(s<target) l++;
        else r--;
    }
    cout<<-1<<"\n";
}
