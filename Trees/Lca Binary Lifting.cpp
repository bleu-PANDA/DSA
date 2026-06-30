#include <bits/stdc++.h>
using namespace std;
// Lowest Common Ancestor - Binary Lifting (Trees)
const int MAXN=100005, LOG=17;
int par[MAXN][LOG], depth[MAXN];
vector<int> adj[MAXN];
void dfs(int u, int p, int d){
    par[u][0]=p; depth[u]=d;
    for(int v:adj[u]) if(v!=p) dfs(v,u,d+1);
}
void buildLCA(int n){
    for(int j=1;j<LOG;j++)
        for(int i=1;i<=n;i++)
            par[i][j]=par[par[i][j-1]][j-1];
}
int lca(int u, int v){
    if(depth[u]<depth[v]) swap(u,v);
    int diff=depth[u]-depth[v];
    for(int j=0;j<LOG;j++) if((diff>>j)&1) u=par[u][j];
    if(u==v) return u;
    for(int j=LOG-1;j>=0;j--)
        if(par[u][j]!=par[v][j]){ u=par[u][j]; v=par[v][j]; }
    return par[u][0];
}
int main(){
    int n,q; cin>>n>>q;
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    dfs(1,0,0); buildLCA(n);
    while(q--){
        int u,v; cin>>u>>v;
        cout << lca(u,v) << "\n";
    }
}
