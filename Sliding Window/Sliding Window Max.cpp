#include <bits/stdc++.h>
using namespace std;
// Sliding Window Maximum using Monotone Deque
vector<int> maxSlidingWindow(vector<int>& nums, int k){
    deque<int> dq;
    vector<int> res;
    for(int i=0;i<(int)nums.size();i++){
        if(!dq.empty()&&dq.front()<=i-k) dq.pop_front();
        while(!dq.empty()&&nums[dq.back()]<nums[i]) dq.pop_back();
        dq.push_back(i);
        if(i>=k-1) res.push_back(nums[dq.front()]);
    }
    return res;
}
int main(){
    int n,k; cin>>n>>k;
    vector<int> a(n);
    for(auto &x:a) cin>>x;
    for(auto v:maxSlidingWindow(a,k)) cout<<v<<" ";
}
