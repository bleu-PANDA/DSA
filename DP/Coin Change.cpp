#include <bits/stdc++.h>
using namespace std;
// Coin Change - DP - Minimum Coins
int main(){
    int n, amount; cin>>n>>amount;
    vector<int> coins(n);
    for(auto &c:coins) cin>>c;
    vector<int> dp(amount+1, INT_MAX);
    dp[0]=0;
    for(int i=1;i<=amount;i++)
        for(int c:coins)
            if(c<=i && dp[i-c]!=INT_MAX)
                dp[i]=min(dp[i], dp[i-c]+1);
    cout<<(dp[amount]==INT_MAX?-1:dp[amount])<<"\n";
}
