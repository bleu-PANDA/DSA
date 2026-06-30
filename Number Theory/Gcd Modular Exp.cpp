#include <bits/stdc++.h>
using namespace std;
// GCD, LCM, Modular Exponentiation - Number Theory
long long power(long long base, long long exp, long long mod){
    long long result=1;
    base%=mod;
    while(exp>0){
        if(exp&1) result=result*base%mod;
        base=base*base%mod;
        exp>>=1;
    }
    return result;
}
int main(){
    long long a,b,m; cin>>a>>b>>m;
    cout<<"GCD: "<<__gcd(a,b)<<"\n";
    cout<<"LCM: "<<a/__gcd(a,b)*b<<"\n";
    cout<<"a^b mod m: "<<power(a,b,m)<<"\n";
}
