#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
// Dijkstra Shortest Path - Graph
void dijkstra(int src, vector<vector<pii>>& adj, vector<int>& dist){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[src]=0; pq.push({0,src});
    while(!pq.empty()){
        auto [d,u]=pq.top(); pq.pop();
        if(d>dist[u]) continue;
        for(auto [w,v]:adj[u])
            if(dist[u]+w < dist[v]){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
    }
}
int main(){
    int n,m; cin>>n>>m;
    vector<vector<pii>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    vector<int> dist(n+1,INT_MAX);
    dijkstra(1,adj,dist);
    for(int i=1;i<=n;i++) cout<<(dist[i]==INT_MAX?-1:dist[i])<<" ";
}
