#include <bits/stdc++.h>
using namespace std;
// 0/1 Knapsack - Classic DP
int main(){
    int n, W; cin>>n>>W;
    vector<int> wt(n),val(n);
    for(auto &x:wt) cin>>x;
    for(auto &x:val) cin>>x;
    vector<vector<int>> dp(n+1, vector<int>(W+1,0));
    for(int i=1;i<=n;i++)
        for(int w=0;w<=W;w++){
            dp[i][w]=dp[i-1][w];
            if(wt[i-1]<=w)
                dp[i][w]=max(dp[i][w], dp[i-1][w-wt[i-1]]+val[i-1]);
        }
    cout << dp[n][W] << "\n";
}
