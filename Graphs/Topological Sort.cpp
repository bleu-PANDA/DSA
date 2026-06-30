#include <bits/stdc++.h>
using namespace std;
// Topological Sort - Kahn's Algorithm (Graphs)
int main(){
    int n,m; cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> indegree(n+1,0);
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++) if(!indegree[i]) q.push(i);
    vector<int> order;
    while(!q.empty()){
        int u=q.front(); q.pop();
        order.push_back(u);
        for(int v:adj[u]) if(!--indegree[v]) q.push(v);
    }
    if(order.size()<n) cout<<"Cycle detected\n";
    else for(auto v:order) cout<<v<<" ";
}
