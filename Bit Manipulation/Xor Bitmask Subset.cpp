#include <bits/stdc++.h>
using namespace std;
// XOR / Bitmask - Count subsets with given XOR
int main(){
    int n,k; cin>>n>>k;
    vector<int> a(n);
    for(auto &x:a) cin>>x;
    int ans=0;
    for(int mask=0;mask<(1<<n);mask++){
        int xorVal=0;
        for(int i=0;i<n;i++) if(mask&(1<<i)) xorVal^=a[i];
        if(xorVal==k) ans++;
    }
    cout << ans << "\n";
}
