#include <bits/stdc++.h>
using namespace std;
// Binary Search in Rotated Sorted Array
int searchRotated(vector<int>& nums, int target){
    int lo=0, hi=nums.size()-1;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(nums[mid]==target) return mid;
        if(nums[lo]<=nums[mid]){
            if(nums[lo]<=target && target<nums[mid]) hi=mid-1;
            else lo=mid+1;
        } else {
            if(nums[mid]<target && target<=nums[hi]) lo=mid+1;
            else hi=mid-1;
        }
    }
    return -1;
}
int main(){
    int n,t; cin>>n>>t;
    vector<int> a(n);
    for(auto &x:a) cin>>x;
    cout << searchRotated(a,t) << "\n";
}
