#include <bits/stdc++.h>
using namespace std;
// Fibonacci using Recursion (with memoization alternative)
map<int,long long> memo;
long long fib(int n){
    if(n<=1) return n;
    if(memo.count(n)) return memo[n];
    return memo[n]=fib(n-1)+fib(n-2);
}
int main(){
    int n; cin>>n;
    cout << fib(n) << "\n";
}
