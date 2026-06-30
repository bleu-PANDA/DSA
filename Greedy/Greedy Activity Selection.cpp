#include <bits/stdc++.h>
using namespace std;
// Greedy Activity Selection - maximum non-overlapping intervals
int main(){
    int n; cin>>n;
    vector<pair<int,int>> intervals(n);
    for(auto &[s,e]:intervals) cin>>s>>e;
    sort(intervals.begin(),intervals.end(),[](auto &a,auto &b){ return a.second<b.second; });
    int count=0, lastEnd=INT_MIN;
    for(auto &[s,e]:intervals){
        if(s>=lastEnd){ count++; lastEnd=e; }
    }
    cout << count << "\n";
}
