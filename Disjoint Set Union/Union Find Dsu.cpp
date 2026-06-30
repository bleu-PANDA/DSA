#include <bits/stdc++.h>
using namespace std;
// Disjoint Set Union - Union Find with path compression and rank
struct DSU {
    vector<int> parent, rank_;
    DSU(int n): parent(n), rank_(n,0){ iota(parent.begin(),parent.end(),0); }
    int find(int x){ return parent[x]==x?x:parent[x]=find(parent[x]); }
    bool unite(int x, int y){
        x=find(x); y=find(y);
        if(x==y) return false;
        if(rank_[x]<rank_[y]) swap(x,y);
        parent[y]=x;
        if(rank_[x]==rank_[y]) rank_[x]++;
        return true;
    }
};
int main(){
    int n,m; cin>>n>>m;
    DSU dsu(n+1);
    while(m--){
        int u,v; cin>>u>>v;
        if(!dsu.unite(u,v)) cout<<"Same component\n";
    }
}
