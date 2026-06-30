#include <bits/stdc++.h>
using namespace std;
// Segment Tree with range sum query and point update
struct SegTree {
    int n;
    vector<long long> tree;
    SegTree(int n): n(n), tree(4*n,0){}
    void build(vector<int>& a, int node, int s, int e){
        if(s==e){ tree[node]=a[s]; return; }
        int mid=(s+e)/2;
        build(a,2*node,s,mid);
        build(a,2*node+1,mid+1,e);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
    void update(int node, int s, int e, int idx, int val){
        if(s==e){ tree[node]=val; return; }
        int mid=(s+e)/2;
        if(idx<=mid) update(2*node,s,mid,idx,val);
        else update(2*node+1,mid+1,e,idx,val);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
    long long query(int node, int s, int e, int l, int r){
        if(r<s||e<l) return 0;
        if(l<=s&&e<=r) return tree[node];
        int mid=(s+e)/2;
        return query(2*node,s,mid,l,r)+query(2*node+1,mid+1,e,l,r);
    }
};
int main(){
    int n,q; cin>>n>>q;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    SegTree st(n+1);
    st.build(a,1,1,n);
    while(q--){
        int t,l,r; cin>>t>>l>>r;
        if(t==1) st.update(1,1,n,l,r);
        else cout<<st.query(1,1,n,l,r)<<"\n";
    }
}
