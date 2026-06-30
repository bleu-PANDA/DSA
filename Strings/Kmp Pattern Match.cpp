#include <bits/stdc++.h>
using namespace std;
// KMP String Pattern Matching
vector<int> buildLPS(const string& pat){
    int m=pat.size();
    vector<int> lps(m,0);
    int len=0,i=1;
    while(i<m){
        if(pat[i]==pat[len]) lps[i++]=++len;
        else if(len) len=lps[len-1];
        else lps[i++]=0;
    }
    return lps;
}
void kmpSearch(const string& text, const string& pat){
    auto lps=buildLPS(pat);
    int n=text.size(),m=pat.size(),i=0,j=0;
    while(i<n){
        if(text[i]==pat[j]){i++;j++;}
        if(j==m){ cout<<"Found at "<<i-j<<"\n"; j=lps[j-1]; }
        else if(i<n && text[i]!=pat[j]){
            if(j) j=lps[j-1]; else i++;
        }
    }
}
int main(){
    string t,p; cin>>t>>p;
    kmpSearch(t,p);
}
