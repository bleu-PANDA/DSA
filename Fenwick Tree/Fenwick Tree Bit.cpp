#include <bits/stdc++.h>
using namespace std;
// Fenwick Tree (Binary Indexed Tree) - Point Update, Prefix Sum Query
struct BIT {
    int n;
    vector<long long> tree;
    BIT(int n): n(n), tree(n+1,0){}
    void update(int i, long long delta){
        for(;i<=n;i+=i&-i) tree[i]+=delta;
    }
    long long query(int i){
        long long s=0;
        for(;i>0;i-=i&-i) s+=tree[i];
        return s;
    }
    long long query(int l, int r){ return query(r)-query(l-1); }
};
int main(){
    int n,q; cin>>n>>q;
    BIT bit(n);
    for(int i=1;i<=n;i++){ int x; cin>>x; bit.update(i,x); }
    while(q--){
        int t,l,r; cin>>t>>l>>r;
        if(t==1) bit.update(l,r);
        else cout<<bit.query(l,r)<<"\n";
    }
}
