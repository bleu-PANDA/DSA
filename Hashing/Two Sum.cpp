#include <bits/stdc++.h>
using namespace std;
// Two Sum - find two indices such that nums[i] + nums[j] == target
int main(){
    int n, target; cin >> n >> target;
    vector<int> nums(n);
    for(auto &x : nums) cin >> x;
    unordered_map<int,int> seen;
    for(int i = 0; i < n; i++){
        if(seen.count(target - nums[i])){
            cout << seen[target-nums[i]] << " " << i << "\n";
            return 0;
        }
        seen[nums[i]] = i;
    }
    cout << -1 << "\n";
}
