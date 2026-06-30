#include <bits/stdc++.h>
using namespace std;
// BFS Shortest Path in Grid - Graphs
int main(){
    int n,m; cin>>n>>m;
    vector<string> grid(n);
    for(auto &row:grid) cin>>row;
    vector<vector<int>> dist(n, vector<int>(m,-1));
    queue<pair<int,int>> q;
    q.push({0,0}); dist[0][0]=0;
    int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
    while(!q.empty()){
        auto [x,y]=q.front(); q.pop();
        for(int d=0;d<4;d++){
            int nx=x+dx[d], ny=y+dy[d];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny]!='#'&&dist[nx][ny]==-1){
                dist[nx][ny]=dist[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
    cout << dist[n-1][m-1] << "\n";
}
