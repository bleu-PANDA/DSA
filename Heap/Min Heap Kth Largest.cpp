#include <bits/stdc++.h>
using namespace std;
// Heap - K-th Largest Element using min-heap
int main(){
    int n,k; cin>>n>>k;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        minHeap.push(x);
        if((int)minHeap.size()>k) minHeap.pop();
    }
    cout << minHeap.top() << "\n";
}
