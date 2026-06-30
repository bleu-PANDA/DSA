#include <bits/stdc++.h>
using namespace std;
// Sieve of Eratosthenes - Number Theory
vector<int> sieve(int n){
    vector<bool> is_prime(n+1,true);
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i*i<=n;i++)
        if(is_prime[i])
            for(int j=i*i;j<=n;j+=i)
                is_prime[j]=false;
    vector<int> primes;
    for(int i=2;i<=n;i++) if(is_prime[i]) primes.push_back(i);
    return primes;
}
int main(){
    int n; cin>>n;
    auto primes=sieve(n);
    for(auto p:primes) cout<<p<<" ";
}
